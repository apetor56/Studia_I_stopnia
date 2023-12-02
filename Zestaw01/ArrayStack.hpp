#ifndef ARRAYSTACK_HPP
#define ARRAYSTACK_HPP

#include <iostream>

template<typename T, int capacity>
class Stack {
public:
    Stack() : tab(new T[capacity]), currentIndex(-1) {}

    ~Stack() {
        delete[] tab;
    }
    
    template<typename U>
    void push(U&& x) {
        if(currentIndex >= capacity)
            throw std::out_of_range("push(): out of range\n");

        currentIndex++;
        tab[currentIndex] = x;
    }

    T pop() {
        if(currentIndex == -1)
            throw std::out_of_range("pop(): out of range\n");

        T value = tab[currentIndex];
        currentIndex--;

        return value; 
    }

    T& top() {
        return (tab + currentIndex);
    }

    int size() {
        return currentIndex + 1;
    }

    bool isEmpty() {
        return (currentIndex == -1) ? true : false;
    }

private:
    T *tab;
    int currentIndex;
};

#endif // ARRAYSTACK_HPP
