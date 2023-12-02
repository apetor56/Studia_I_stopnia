#ifndef LINKEDSTACK_HPP
#define LINKEDSTACK_HPP

#include <iostream>

struct Node {
    Node *prev;
    Node *next;
    int value;
};

class Stack {
public:
    Stack() : currentSize(0) {};
    
    ~Stack() {
        if(top != nullptr)
            while(top->prev != nullptr) {
                Node *tmp = top;
                top = top->prev;
                delete tmp;
            }
    }

    void push(int x) {
        Node *newNode = new Node;
        currentSize++;
        newNode->value = x;
        
        if(top == nullptr)
            newNode->prev = nullptr;
        else
            newNode->prev = top;

        top = newNode;
        newNode->next = nullptr;
    }

    int pop() {
        if(currentSize == 0)
            throw std::out_of_range("none pointer to delete\n");
        else {
            int v = top->value;
            Node *tmp = top;
            top = top->prev;

            delete tmp;
            currentSize--;
            return v;
        }
    }

    size_t size() {
        return currentSize;
    }

    bool isEmpty() {
        return (currentSize == 0) ? true : false;
    }
private:
    Node *top;
    size_t currentSize;
};
#endif // LINKEDSTACK_HPP