#ifndef LINKEDQUEUE_HPP
#define LINKEDQUEUE_HPP

#include <iostream>

template<typename T>
struct Node {
    Node<T> *next;
    T value;
};

template<typename T>
class Queue {
public:
    Queue() : first(nullptr), last(nullptr), currentSize(0) {}

    ~Queue() {
        while(first != nullptr) {
            Node<T> *tmp = first;
            first = first->next;
            delete tmp;
        }
    }

    template<typename U>
    void push(U&& x) {
        Node<T> *newNode = new Node<T>;

        if(currentSize == 0)            // jesli nie ma jeszcze ani jednego wezla
            first = newNode;            // to pierwszy w kolejce jest nowo dodany element  
        else
            last->next = newNode;

        last = newNode;             // ostanim elementem w kolejce jest nowo stworzony element
        newNode->next = nullptr;
        newNode->value = x;
        currentSize++;
    }

    T pop() {
        if(currentSize == 0)
            throw std::out_of_range("pop(): out of range\n");
    
        Node<T> *tmp = first;
        T x = first->value;
        first = first->next;

        currentSize--;
        delete tmp;         // usuwamy element, ktory byl pierwszy w kolejce
        return x;
    }

    size_t size() {
        return currentSize;
    }

    bool isEmpty() {
        return (currentSize == 0) ? true : false;
    }
private:
    Node<T> *first, *last;
    int currentSize;
};

#endif // LINKEDQUEUE_HPP