#include <iostream>
#include "SetLinked.hpp"

int main() {
    SetLinked<int, 5> set, set2;
    std::string segment = std::string(50, '-');

    set.put(0);     set2.put(0);
    set.put(1);     set2.put(1);
    set.put(2);     set2.put(2);
    set.put(3);     set2.put(3);
    set.put(4);     set2.put(4);
    set.put(5);     set2.put(5);
    set.put(11);    set2.put(12);
    set.put(13);   set2.put(14);
    set.put(1700);    set2.put(1701);
    set.put(-14);    set2.put(-13);

    std::cout << set << '\n' << set2 << '\n' << segment << '\n';

    std::cout << SetLinked<int, 5>::setUnion(set, set2) << segment << '\n';

    std::cout << SetLinked<int, 5>::setIntersection(set, set2) << segment << '\n';

    std::cout << set / set2 << segment << '\n';

    std::cout << set2 / set << segment << '\n';

    std::cout << (set2 == set) << '\n' << segment << '\n';

    for(int i = 0; i < 6; i++) {
        set.remove(i);
    }
    std::cout << set << segment << '\n';

    std::cout << set2.find(1701) << '\n';
}