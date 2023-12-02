#!/bin/bash

programs=(./Points.x ./KDPoints.x)
DATA=./

DIM=5
N=100
MAX=500

n=0
function test_algorithm () {
    ./Generator.x $1 $2 $3 > $DATA/input.txt
    ./Points.x $DATA/input.txt > $DATA/base_output.txt
    ./KDPoints.x $DATA/input.txt "-test" > $DATA/kdbase_output.txt

    if cmp -s $DATA/base_output.txt $DATA/kdbase_output.txt; then
        echo -e "test $n: $(tput setaf 2)SUCCEED $(tput setaf 7)"
    else
        echo -e "test $n: $(tput setaf 1)FAILURE $(tput setaf 7)"
    fi
    ((n++))
}

echo -e "$(tput setaf 7)"
make

if [ $# -gt 1 ] && [ $1 -gt 0 ] && [ $2 -gt 0 ] && [ $3 -gt 0 ]
then
    DIM=$1
    N=$2
    MAX=$3
fi

for((i=0; i<10; i++))
do
    test_algorithm $DIM $N $MAX
done