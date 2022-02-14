#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

template<typename T>
struct Node {
        Node(const T& _val, Node * _prev, Node *_next) : val(_val), prev(_prev), next(_next) {}
        T val;
        Node *prev;
        Node *next;
};

template<typename T>
class List {
public:
    using NodePtr = Node<T> *;
    List() : currentSize(0), head(nullptr), tail(nullptr) {}

    ~List() {
        NodePtr tmp = head;
        while(tmp != nullptr) {
            NodePtr removeNode = tmp;
            tmp = tmp->next;
            delete removeNode;
        }
    }

    template<typename U>
    void push_front(U&& x) {
        if(!head) {
            head = new Node<T>(std::forward<U>(x), nullptr, nullptr);
            tail = head;
        }
        else {
            head->prev = new Node<T>(std::forward<U>(x), nullptr, head);
            head = head->prev;
        }
        currentSize++;
    }

    T pop_front() {
        if(isEmpty())
            throw std::out_of_range("pop_front(): list is empty\n");

        T x = std::forward<T>(head->val);
        NodePtr tmp = head;
        head = head->next;

        currentSize--;
        delete tmp;
        return x;
    }

    template<typename U>
    void push_back(U&& x) {
        if(!tail) {
            tail = new Node<T>(std::forward<U>(x), nullptr, nullptr);
            head = tail;
        }
        else {
            tail->next = new Node<T>(std::forward<U>(x), tail, nullptr);
            tail = tail->next;
        }
        currentSize++;
    }

    T pop_back() {
        if(isEmpty())
            throw std::out_of_range("pop_back(): list is empty\n");
        
        T x = std::forward<T>(tail->val);
        NodePtr tmp = tail;
        tail = tail->prev;

        currentSize--;
        delete tmp;
        return x;
    }

    size_t size() {
        return currentSize;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    void clear() {
        NodePtr tmp = head;
        while(tmp != nullptr) {
            NodePtr removeNode = tmp;
            tmp = tmp->next;

            delete removeNode;
            currentSize--;
        }
    }

    int find(T x) {
        NodePtr tmp = head;
        for(size_t i = 0; i < currentSize; i++) {
            if(tmp->val == x)
                return i;
        }
        return -1;
    }

    T erase(int i) {
        if(isEmpty())
            throw std::out_of_range("erase(): list is empty\n");

        NodePtr tmp = head;
        for(int j = 0; j < i; j++)
            tmp = tmp->next;
        
        T y = std::forward<T>(tmp->val);
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;

        currentSize--;
        delete tmp;
        return y;
    }

    template<typename U>
    void insert(int i, U&& x) {
        if(i == 0)
            push_front(std::forward<U>(x));
        else {
            NodePtr tmp1 = head;
            NodePtr tmp2;
            for(int j = 0; j < i - 1; j++)
                tmp1 = tmp1->next;
            
            tmp2 = tmp1->next;
            NodePtr node = new Node<T>(std::forward<U>(x), tmp1, tmp2);
            tmp1->next = node;
            tmp2->prev = node;

            currentSize++;
        }
    }

    int remove(T x) {
        int counter = 0;
        NodePtr tmp = head;

        while(tmp != nullptr) {
            if(tmp->val == x) {
                if(tmp == head)
                    pop_front();
                else if(tmp == tail)
                    pop_back();
                else {
                    NodePtr removeNode = tmp;
                    tmp->next->prev = tmp->prev;
                    tmp->prev->next = tmp->next;

                    currentSize--;
                    delete removeNode;
                }
                counter++;
            }
            tmp = tmp->next;
        }

        return counter;
    }

    NodePtr getHead() {
        return head;
    }

private:
    size_t currentSize;
    NodePtr head, tail;
};

#endif // LINKEDLIST_HPP