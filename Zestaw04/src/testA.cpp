#include <iostream>
#include "Graph.hpp"

int main() {
    Graph<20> graph;

    for(int i = 0; i < 7; i++) {
        graph.addVertex();
    }

    graph.addEdge(0, 1);    graph.setEdge(1, 0, 1);
    graph.addEdge(1, 2);    graph.setEdge(2, 1, 2);
    graph.addEdge(2, 3);    graph.setEdge(3, 2, 3);
    graph.addEdge(3, 0);    graph.setEdge(4, 3, 0);

    graph.addEdge(0, 2);    graph.setEdge(5, 0, 2);

    graph.addEdge(3, 4);    graph.setEdge(6, 3, 4);
    graph.addEdge(4, 0);    graph.setEdge(7, 4, 0);
    graph.addEdge(4, 2);    graph.setEdge(8, 4, 2);

    graph.addEdge(4, 5);    graph.setEdge(9, 4, 5);
    graph.addEdge(4, 6);    graph.setEdge(10, 4, 6);

    graph.saveToImage("graph1");

    graph.removeEdge(0, 2);
    graph.removeVertex(4);

    std::vector<int> vec;
    for(int i = 0; i < 7; i++) {
        vec = graph.neighbours(i);
        for(auto& x : vec) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }

    graph.saveToImage("graph2");
}