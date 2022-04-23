#ifndef DICSAMPLE_HPP
#define DICSAMPLE_HPP

#include <iostream>
#include <ctime>

uint32_t find_complexity;
uint32_t remove_complexity;

template<uint32_t capacity>
class DictonarySample {
public:
    DictonarySample() : size(0) {}

    void put(std::string s) {
        if(find(s) == -1) {
            if(size == capacity) {
                throw std::out_of_range("put(): out of range\n");
            }

            tab[size] = s;
            size++;
        }
    }

    void remove(std::string s) {
        int r = find(s);
        remove_complexity = find_complexity;

        if(r != -1) {
            tab[r] = tab[size - 1];
            tab[size - 1] = "";

            remove_complexity++;
            size--;
        }
    }

    int find(std::string s) {
        find_complexity = 0;

        for(int i = 0; i < size; i++) {
            if(tab[i] == s) {
                find_complexity = i + 1;
                return i;
            }
        }
        return -1;
    }

    void show() {
        for(int i = 0; i < size; i++) {
            std::cout << tab[i] << ' ';
        }
        std::cout << '\n';
    }

private:
    std::string tab[capacity];
    int size;
};

#endif // DICSAMPLE_HPP