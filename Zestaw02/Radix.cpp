#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
// #include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"

int size = 0;

void radix(std::vector<int>& v) {
    // Queue<int, 100000> queue[10];
    Queue<int> queue[10];
    int p, r, digit;

    for(int i = 0; i < size; i++) {
        p = pow(10, i + 1);
        for(auto& x : v) {
            r = x % static_cast<int>(pow(10, i));
            digit = (x % p - r) / pow(10, i);
            queue[digit].push(x);
        }

        int pos = 0;
        for(int j = 0; j < 10; j++) {
            while(!queue[j].isEmpty()) {
                int val = queue[j].pop();
                v.at(pos) = val;
                pos++;
            }
        }
    }
}

int main(void) {
    std::vector<int> v;

    int x, max = 0;
    while(std::cin >> x) {
        v.push_back(x);
        if(x > max)
            max = x;
    }

    while(max != 0) {
        max /= 10;
        size++;
    }

    radix(v);
    for(auto& x : v)
        std::cout << x << '\n';
}