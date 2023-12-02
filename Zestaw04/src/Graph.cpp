#include <iostream>
#include <chrono>
#include "Graph.hpp"

int main() {
    std::cout << "cooo\n";

    constexpr int size = 500;
    double measurements[size] {};

    for(int k = 0; k < 500; k++) {
        Graph<500> graph;
        for(int i = 0; i < size; i++) {
            graph.addVertex();
        }
        for(int i = 0; i < size; i++) {
            auto start = std::chrono::high_resolution_clock::now();
                graph.removeVertex(i);
            auto end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> elapsed = end - start;
            measurements[i] += elapsed.count();
        }
    }

    for(int i = 0; i < size; i++) {
        std::cout << i << ' ' << measurements[i] << '\n';
    }
}