#!/bin/bash

DATA="./data"
program="./BubbleSort.x"
generator="./Generator.x"
FLAG="-cmp"
N=300
MAX=10000

make

> $DATA/complexity.txt

for((i=0; i<1000; i++))
do
    j=$(($N * ($i + 1)))
    $generator $j $MAX > $DATA/input.txt
    $program $j $MAX $FLAG < $DATA/input.txt >> $DATA/complexity.txt
done