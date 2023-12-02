EXE=./bin
SRC=./src
PLOT=./plot

if [ "$1" == "-data" ]; then
    ${EXE}/PriorityQueue.exe > ${PLOT}/output_A.txt
elif [ "$1" == "-test" ]; then
    ${EXE}/testA.exe
fi

cd ./plot
    gnuplot plot_A.gnu
cd ..