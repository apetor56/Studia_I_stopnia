EXE=./bin
SRC=./src
PLOT=./plot

if [ "$1" == "-data" ]; then
    ${EXE}/BinaryHeap.exe > ${PLOT}/output_B.txt
elif [ "$1" == "-test" ]; then
    ${EXE}/testB.exe
fi

cd ./plot
    gnuplot plot_B.gnu
cd ..