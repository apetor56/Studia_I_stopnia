EXE=./bin
SRC=./src
PLOT=./plot
GRAPH=./graph

if [ "$1" == "-data" ]; then
    ${EXE}/Graph.exe > ${PLOT}/output_A.txt
elif [ "$1" == "-A" ]; then
    cd ${EXE}
    ./Graph.exe
    cd ../graph
    dot -Tjpg "A.dot" -o "A.jpg"
elif [ "$1" == "-B" ]; then
    cd ${EXE}
    ./Crossing.exe
    cd ../graph
    dot -Tjpg "B.dot" -o "B.jpg"
elif [ "$1" == "-C" ]; then
    cd ${EXE}
    ./KnightsTour.exe
    cd ../graph
    dot -Tjpg "knight.dot" -o "knight.jpg"
elif [ "$1" == "-plot" ]; then
    cd ${EXE}
    ./A.exe > ../plot/output_A.txt
    cd ../plot
    gnuplot plot_A.gnu
    cd ..
fi