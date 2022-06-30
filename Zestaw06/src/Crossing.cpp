#include <iostream>
#include "Graph.hpp"

int main(int argc, const char *argv[]) {
    Graph<int> graph;

    for(int i = 1; i <= 13; i++) {
        graph.addVertex(i);
    }

    graph.addEdge(1, 10);
	graph.addEdge(1, 6);
	graph.addEdge(1, 5);
	graph.addEdge(1, 7);
	graph.addEdge(1, 11);
	graph.addEdge(1, 8);
	graph.addEdge(2, 10);
	graph.addEdge(2, 6);
	graph.addEdge(2, 5);
	graph.addEdge(2, 11);
	graph.addEdge(2, 12);
	graph.addEdge(2, 7);
	graph.addEdge(2, 8);
	graph.addEdge(2, 9);
	graph.addEdge(3, 10);
	graph.addEdge(3, 11);
	graph.addEdge(3, 12);
	graph.addEdge(3, 13);
	graph.addEdge(3, 6);
	graph.addEdge(4, 7);
	graph.addEdge(4, 10);
	graph.addEdge(5, 1);
	graph.addEdge(5, 11);
	graph.addEdge(5, 7);
	graph.addEdge(5, 8);
	graph.addEdge(5, 9);
	graph.addEdge(5, 2);
	graph.addEdge(5, 12);
	graph.addEdge(6, 7);
	graph.addEdge(6, 1);
	graph.addEdge(6, 2);
	graph.addEdge(6, 3);
	graph.addEdge(6, 11);
	graph.addEdge(6, 12);
	graph.addEdge(6, 13);
	graph.addEdge(7, 12);
	graph.addEdge(7, 11);
	graph.addEdge(7, 2);
	graph.addEdge(7, 2);
	graph.addEdge(7, 5);
	graph.addEdge(7, 6);
	graph.addEdge(7, 4);
	graph.addEdge(7, 10);
	graph.addEdge(8, 2);
	graph.addEdge(8, 1);
	graph.addEdge(8, 5);
	graph.addEdge(8, 12);
	graph.addEdge(8, 11);
	graph.addEdge(9, 2);
	graph.addEdge(9, 12);
	graph.addEdge(9, 5);
	graph.addEdge(10, 1);
	graph.addEdge(10, 2);
	graph.addEdge(10, 3);
	graph.addEdge(10, 7);
	graph.addEdge(10, 4);
	graph.addEdge(11, 3);
	graph.addEdge(11, 2);
	graph.addEdge(11, 1);
	graph.addEdge(11, 7);
	graph.addEdge(11, 8);
	graph.addEdge(11, 5);
	graph.addEdge(11, 6);
	graph.addEdge(12, 3);
	graph.addEdge(12, 2);
	graph.addEdge(12, 6);
	graph.addEdge(12, 5);
	graph.addEdge(12, 7);
	graph.addEdge(12, 8);
	graph.addEdge(12, 9);
	graph.addEdge(13, 3);
	graph.addEdge(13, 6);

    graph.saveToImage("B");
}