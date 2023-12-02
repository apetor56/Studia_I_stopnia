#include <iostream>
#include <ctime>
#include "SetSimple.hpp"

int main() {
    uint32_t size;
    uint32_t random;
    srand(time(NULL));

    for(int i = 1; i <= 10000; i++) {
        size = i * 10;
        SetSimple A(size), B(size);

        for(auto j = 0; j < size / 2; j++) {
            random = rand() % size;

            while(A.get(random) == true) {
                random = rand() % size;
            }
            A.put(random);

            random = rand() % size;
            while(B.get(random) == true) {
                random = rand() % size;
            }
            B.put(random);
        }
        SetSimple::setUnion(A, B);
        SetSimple::intersection(A, B);

        std::cout << size / 2 << ' ' << unionComplexity << ' ' << intersectionComplexity << '\n';
    }
}