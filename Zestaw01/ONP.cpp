#include <iostream>
#include "ArrayStack.hpp"

int main() {
    std::string input, output;
    Stack<std::string, 1000000> stack;

    while(std::cin >> input) {
        if(input == "(" || input == "+" || input == "-" || input == "/" || input == "*")
            stack.push(input);
        else if(input == ")") {
            std::string pop;
            while( (pop = stack.pop()) != "(") {
                output = output + pop + " ";
            }
        }
        else
            output = output + input + " ";
    }
    for(size_t i = 0; i < output.size() - 1; i++)
        std::cout << output[i];
}