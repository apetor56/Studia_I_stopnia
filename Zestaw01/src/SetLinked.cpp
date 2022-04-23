#include <iostream>
#include <ctime>
#include "SetLinked.hpp"

int main() {
    SetLinked<int> A, B;
    int randA, randB;
    
    srand(time(NULL));

    for(int i = 0; i < 4000; i++) {
        randA = rand() % 10000;
        randB = rand() % 20000;
        
        while(A.find(randA) != -1) {
            randA = rand() % 10000;
        }
        A.put(randA);

        while(B.find(randB) != -1) {
            randB = rand() % 10000;
        }
        B.put(randB);
        
        A.find(randA);
        SetLinked<int>::intersection(A, B);

        std::cout << A.size() << ' ' << findComplexity << ' ' << intersectionComplexity << '\n';        
    }
}