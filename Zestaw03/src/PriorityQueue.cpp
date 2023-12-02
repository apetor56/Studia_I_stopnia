#include <iostream>
#include <chrono>
#include "PriorityQueue.hpp"

int main() {
    constexpr unsigned int i_it = 10u;
    constexpr unsigned int j_it = 100u;
    double measurements[i_it * j_it] {};

    for(int k = 0; k < 500; k++) {
        PriorityQueue<int, 10> queue;

        for(unsigned int i = 0u; i < i_it; i++) {
            for(unsigned int j = 0; j < j_it; j++) {
                queue.enqueue(i * j + j, i);
            }
        }

        for(unsigned int i = 0u; i < i_it * j_it; i++) {
            auto start = std::chrono::high_resolution_clock::now();
                queue.dequeue();
            auto end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> elapsed = end - start;
            measurements[i] += elapsed.count();
        }
    }

    for(auto i = 0u; i < i_it * j_it; i++) {
        std::cout << i << ' ' << measurements[i] << '\n';
    }
}