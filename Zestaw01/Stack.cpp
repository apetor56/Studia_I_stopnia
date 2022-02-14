#include <iostream>
#include "ArrayStack.hpp"
// #include "LinkedStack.hpp"

int main(int argc, const char *argv[]) {
    Stack<int, 1000000> stack;
    
    int iterations;
    int number;
    std::cin >> iterations;

    try {
        for(int i = 0; i < iterations; i++) {
            char option;
            std::cin >> option;
            switch(option) {
            case 'A':
                std::cin >> number;
                stack.push(number);
                break;
            case 'D':
                if(stack.isEmpty()) {
                    std::cout << "EMPTY\n";
                    break;
                }
                number = stack.pop();
                std::cout << number << '\n';
                break;
            case 'S':
                std::cout << stack.size() << '\n';
                break;
            }
        }
    }
    catch(std::out_of_range& e) {
        std::cout << e.what();
    }
}