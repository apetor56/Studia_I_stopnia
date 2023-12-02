#include <iostream>
#include <iterator>
#include <fstream>
#include "Dict.hpp"

int main(int argc, const char *argv[]) {
    Dict<std::string, std::string> dict;

    std::fstream file(argv[1]);
    std::string key, value;
    std::pair<std::string, std::string> pair;

    while(file >> key >> value) {
        pair.first = key;
        pair.second = value;
        dict.insert(pair);
    }

    while(std::cin >> key) {
        if(dict.find(key))
            std::cout << dict[key] << '\n';
        
        else std::cout << "-\n";
    }
}
