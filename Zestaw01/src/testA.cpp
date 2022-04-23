#include <iostream>
#include "SetSimple.hpp"

int main() {
    SetSimple A(10), B(10);

    A.put(3);   B.put(0);
    A.put(4);   B.put(1);
    A.put(5);   B.put(2);
    A.put(6);   B.put(3);
    A.put(7);   B.put(4);

    std::cout << SetSimple::setUnion(A, B) << '\n';
    std::cout << SetSimple::intersection(A, B) << '\n';
    std::cout << std::string(50, '-') << '\n';

    std::cout << A / B << '\n';
    std::cout << B / A << '\n';
    std::cout << std::string(50, '-') << '\n';

    std::cout << A.get(1) << '\n';      // czy 1 należy do A
    std::cout << B.get(4) << '\n';
    std::cout << std::string(50, '-') << '\n';

    A.erase(6);
    std::cout << A << '\n';
}