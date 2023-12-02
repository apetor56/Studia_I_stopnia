#include <iostream>
#include <chrono>
#include "Graph.hpp"

int main() {
    Graph<int> graph;
    const int size = 500;
    double measurements[size] {};

    for(int k = 0; k < 1000; k++) {
        for(int i = 0; i < size; i++) {
            graph.addVertex(i);
        }

        for(int i = 0; i < size; i++) {
            auto start = std::chrono::high_resolution_clock::now();
                graph.removeVertex(i);
            auto end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> elapsed = end - start;

            measurements[size - i - 1] += elapsed.count();
        }
    }

    for(int i = 0; i < size; i++) {
        std::cout << i << ' ' << measurements[i] << '\n';
    }
}