#include <iostream>
#include "ArrayQueue.hpp"
// #include "LinkedQueue.hpp"

int main() {
    Queue<int, 8196> queue;
    // Queue<int> queue; 

    int iterations;
    std::cin >> iterations;
    int number;
    char option;

    for (int i = 0; i < iterations; i++) {
        std::cin >> option;
        try {
            switch (option) {
            case 'A':
                std::cin >> number;
                queue.push(number);
                break;
            case 'D':
                if(queue.isEmpty()) {
                        std::cout << "EMPTY\n";
                        break;
                }
                number = queue.pop();
                std::cout << number << '\n';
                break;
            case 'S':
                std::cout << queue.size() << '\n';
                break;
            }
        }
        catch(std::out_of_range& e) {
            std::cout << e.what();
        }
    }
}