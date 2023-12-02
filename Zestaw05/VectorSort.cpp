#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main(int argc, const char *argv[]) {
    std::vector<int> vec(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
    auto beginIterator = vec.begin();
    auto endIterator = vec.end();

    if(argc != 1 && argc == 3) {
        int begin = std::stoi(argv[1]);
        int end = std::stoi(argv[2]);
        if(end > (int)vec.size() || begin > (int)vec.size()) {
            std::cerr << "Passed wrong indexes\n";
            return -1;
        }

        endIterator = vec.begin();
        for(int i = 0; i < begin; i++) {
            beginIterator++;
            endIterator++;
        }
        for(int i = begin; i < end; i++)
            endIterator++;
    }

    std::sort(beginIterator, endIterator);
    for(auto& x : vec)
        std::cout << x << '\n';
}