#include <iostream>
#include "SetLinked.hpp"

int main() {
    SetLinked<int> A, B;

    A.put(1);  B.put(10);
    A.put(2);  B.put(11);
    A.put(3);  B.put(12);
    A.put(4);  B.put(1);
    A.put(5);  B.put(2);
    A.put(6);  B.put(3);
    A.put(7);  B.put(4);
    
    SetLinked<int> C = SetLinked<int>::setUnion(A, B);
    C.show();
    std::cout << std::string(50, '-') << '\n';

    C = SetLinked<int>::intersection(A, B);
    C.show();
    std::cout << std::string(50, '-') << '\n';

    C = A / B;
    C.show();
    std::cout << std::string(50, '-') << '\n';

    C = B / A;
    C.show();
    std::cout << std::string(50, '-') << '\n';

    A.remove(1);
    A.remove(7);
    A.show();
    std::cout << std::string(50, '-') << '\n';

    std::cout << A.find(1) << ' ' << A.find(4) << '\n';
    std::cout << std::string(50, '-') << '\n';

    SetLinked<int> D = A;
    std::cout << (D == A) << '\n';
    D.put(10);
    std::cout << (D == A) << '\n';
}