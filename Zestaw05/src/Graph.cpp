#include <iostream>
#include <chrono>
#include <cstring>
#include "Graph.hpp"

int main(int argc, const char *argv[]) {
    Graph<3> graph;

    for(int i = 0; i < 3; i++) {
        graph.addVertex();
    }

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);

    if(argc == 2 && strcmp(argv[1],"-graph") == 0) {
        graph.saveToImage("graph");
    }
}