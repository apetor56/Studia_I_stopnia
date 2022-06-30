#include <iostream>
#include <chrono>
#include <ctime>
#include "BinaryHeap.hpp"

using el = BinaryHeap<int>::element;

int main() {
    constexpr int size = 1000u;
    double measurements[size] {};
    std::cout.precision(8);

    srand(time(NULL));

    for(int n = 0; n < 10000; n++) {
        BinaryHeap<int> heap(size);

        for(int i = 0; i < size; i++) {
            int r1 = static_cast<int>(rand() % 100000);
            int r2 = static_cast<int>(rand() % 100000);
            heap.enqueue(el(r1, r2));
        }

        for(int i = 0; i < size; i++) {
            auto start = std::chrono::high_resolution_clock::now();
                heap.dequeue();
            auto end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> elapsed = end - start;
            measurements[size - i - 1] += elapsed.count();
        }
    }

    for(int i = 0; i < size; i++) {
        std::cout << std::fixed << i + 1 << ' ' << measurements[i] << '\n';
    }
}