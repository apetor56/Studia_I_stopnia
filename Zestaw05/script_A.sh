EXE=./bin
SRC=./src
PLOT=./plot
GRAPH=./graph

if [ "$1" == "-data" ]; then
    ${EXE}/Graph.exe > ${PLOT}/output_A.txt
elif [ "$1" == "-test" ]; then
    ${EXE}/testA.exe
elif [ "$1" == "-graph" ]; then
    cd ${EXE}
    ./Graph.exe $1
    cd ../graph
    dot -Tjpg graph.dot -o graph.jpg
fi