#include <iostream>
#include <chrono>
#include <cstring>
#include <vector>
#include "Graph.hpp"

int main(int argc, const char *argv[]) {
    Graph<int> graph;

    // try {
        for(unsigned int i = 0u; i < 5; i++) {
            graph.addVertex(i);
        }

        graph.addEdge(0, 1, 5);    
        graph.addEdge(1, 2, 10);
        graph.addEdge(2, 3, 15);
        graph.addEdge(3, 0, 20);
        graph.addEdge(4, 0, 25);
        graph.addEdge(4, 1, 30);
        graph.addEdge(4, 2, 35);

        graph.removeVertex(2);

        graph.saveToImage("A");

        auto neighbours = graph.neighbours(4);
        for(auto x : neighbours) {
            std::cout << x << '\n';
        }
    // }
    /* catch(GraphException& e) {
        std::cout << e.what() << '\n';
    }
    catch(...) {
        std::cout << "other exception\n";
    } */
}