#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>
#include <cstring>

unsigned int compare = 0;

template<typename RandomAccessIterator>
void sort(RandomAccessIterator begin, RandomAccessIterator end) {
    for(auto i = begin; i < end - 1; i++) {
        bool sorted = true;
        for(auto j = end - 1; j > i; j--) {
            compare++;
            if(*(j - 1) > *j) {
                std::swap(*(j - 1), *j);
                sorted = false;
            }
        }
        if(sorted)
            break;
    }
}

int main(int argc, const char *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::vector<int> vec(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
    auto beginIterator = vec.begin();
    auto endIterator = vec.end();

    if(argc != 1 && argc == 3) {
        int begin = std::stoi(argv[1]);
        int end = std::stoi(argv[2]);
        if(end > (int)vec.size() || begin > (int)vec.size()) {
            std::cout << "Passed wrong indexes\n";
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

    auto start = std::chrono::high_resolution_clock::now();
    sort(beginIterator, endIterator);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start) * 1e-4;

    if(argc == 2 && strcmp(argv[1], "-ncout") == 0) {
        std::cerr << vec.size() << ' ' << elapsed.count() << ' ';
        return 1;
    }

    if(argc == 4 && strcmp(argv[3], "-cmp") == 0) {
        std::cout << vec.size() << ' ' << compare << '\n';
        return 2;
    }
    
    for(auto& x : vec)
        std::cout << x << '\n';
}