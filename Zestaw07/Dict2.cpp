#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include "Dict.hpp"

int main(int argc, const char *argv[]) {
    Dict<std::string, std::string> dict;

    std::fstream file(argv[1]);
    std::string key, value;
    std::pair<std::string, std::string> pair;

    while(file >> key >> value) {
        pair.first = key;

        if(value.find('_') != std::string::npos) {
            std::replace(value.begin(), value.end(), '_', ' ');
        }
        pair.second = value;
        
        dict.insert(pair);
    }

    std::string s;
    while(std::cin >> s) {
        std::cout << dict[s] << "\n\n";
    }
}
