#ifndef ARRAYQUEUE_HPP
#define ARRAYQUEUE_HPP

#include <iostream>

template<typename T, int capacity>
class Queue {
public:
    Queue() : head(0), tail(0), currentSize(0) {}

    void push(T x) {
        if(head == tail && currentSize != 0)
            throw std::out_of_range("push: out of range\n");

        buffer[tail] = x;
        tail = (tail + 1) % capacity;
        currentSize++;
    }

    T pop() {
        if(currentSize == 0)
            throw std::out_of_range("pop: out of range\n");
        
        T temp = buffer[head];
        head = (head + 1) % capacity;
        currentSize--;
        return temp;
    }

    int size() {
        return currentSize;
    }

    bool isEmpty() {
        return currentSize == 0 ? true : false;
    }

private:
    T buffer[capacity];
    int head, tail;
    int currentSize;
};

#endif // ARRAYQUEUE_HPP