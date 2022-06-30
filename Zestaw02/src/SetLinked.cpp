#include <iostream>
#include <chrono>
#include "SetLinked.hpp"

int main() {
    int size = 500;
    
    double *sum_of_measurements = new double[size]();

    // std::cout.precision(8);

    for(int i = 0; i < 1000; i++) {
        SetLinked<int, 3> set_A;
        for(int j = 1; j <= size; j++) {
            // start measurement
            auto start = std::chrono::high_resolution_clock::now();

            set_A.put(j);

            // end measurement
            auto end = std::chrono::high_resolution_clock::now();

            // elapsed time
            std::chrono::duration<double> elapsed = end - start;

            // sum of 1000 measurements for one specific step
            sum_of_measurements[j - 1] += elapsed.count();
        }
    }

    for(int i = 0; i < size; i++) {
        std::cout << i << ' ' << sum_of_measurements[i] << '\n';
    }

    delete[] sum_of_measurements;
}