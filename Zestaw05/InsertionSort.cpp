#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>
#include <cstring>

template<typename RandomAccessIterator>
void sort(RandomAccessIterator begin, RandomAccessIterator end) {
    auto tmp = *begin;
    for(auto i = begin + 1; i != end; i++) {
        tmp = *i;
        auto j = i - 1;

        while(j >= begin && *j > tmp) {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = tmp;
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
        std::cerr << elapsed.count() << ' ';
        return 1;
    }

    for(auto& x : vec)
        std::cout << x << '\n';
}