#include <iostream>
#include <ctime>
#include "DictonarySample.hpp"

int main() {
    DictonarySample<1000> dict;
    std::string s[1000];
    int size = 1000;

    srand(time(NULL));

    for(int i = 0; i < size; i++) {
        std::cin >> s[i];
        dict.put(s[i]);
    }

    int index;
    for(int i = 0; i < size; i++) {
        index = rand() % (size - i);
        dict.remove(s[index]);

        std::cout << size - i << ' ' << find_complexity << ' ' << remove_complexity << '\n';
    }
}