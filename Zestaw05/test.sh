#!/bin/bash

algorithms=(BubbleSort SelectionSort InsertionSort CountingSort)
programs=(./Generator.x ./BubbleSort.x ./SelectionSort.x ./InsertionSort.x ./CountingSort.x)
DATA=./data
MAX=10000
N=10000

n=0
function test_algorithm () {
    ./Generator.x $1 $2 > $DATA/input.txt
    ${programs[$3]} $4 $5 < $DATA/input.txt > $DATA/output.txt 2> $DATA/measures.txt
    ./VectorSort.x $4 $5 < $DATA/input.txt > $DATA/vectorOutput.txt
    if cmp -s $DATA/output.txt $DATA/vectorOutput.txt; then
        echo -e "test $n: $(tput setaf 2)SUCCEED $(tput setaf 7)"
    else
        echo -e "test $n: $(tput setaf 1)FAILURE $(tput setaf 7)"
    fi
    ((n++))
}

make

echo $(tput setaf 7)
if [ "$1" == "-h" ]
then
    echo "$0  [number] [max] [begin] [end]"
    echo -e "\tnumber - number of elements to sort"
    echo -e "\tmax    - maximum value of vector's elements"
    echo -e "\tbegin  - start point of sort (begin index)"
    echo -e "\tend    - end point of sort (end index)"
    exit 1
fi

for((i=0; i<${#algorithms[*]}; i++))
do
    j=$(expr $i + 1)
    echo "$j: ${algorithms[$i]}"
done
echo -e -n "\nSelect one of algorithms: "
read option

if [ $# -gt 1 ] && [ $1 -gt 0 ] && [ $2 -gt 0 ]
then
    N=$1
    MAX=$2
fi

for((i=0; i<10; i++))
do
    test_algorithm $N $MAX $option $3 $4
done

echo -e "\nDo you want to measure time of algorithms duration? Type 'y' or 'n': "
read option

if [ $option == 'n' ];
then
    exit 1
else
    M=10000
    ./Generator.x $M $MAX > $DATA/input.txt
    > $DATA/measures.txt
    NCOUT="-ncout"
    
    echo "Enter number of repetition: "
    read N
    for (( i=1; i<=N; i++ ))
    do
        j=$(($M + ($i - 1) * 200))
        echo -n "$j: "
        for(( k=1; k<${#programs[*]}; k++ ))
        do
            ${programs[$k]} $NCOUT < $DATA/input.txt 2>> $DATA/measures.txt
            echo -n -e "$(tput setaf 3)${algorithms[$(($k-1))]} $(tput setaf 7)| "
        done
        echo "$(tput setaf 2)DONE $(tput setaf 7)"
        ./Generator.x 200 $MAX >> $DATA/input.txt
    done
fi