#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

template<typename T>
class List {
public:
    template<typename U>
    friend std::ostream& operator<<(std::ostream& stream, List<U>& list);

    List() noexcept
        : currentSize(0), head(nullptr), tail(nullptr) {}

    ~List() {
        Node *tmp = head;
        for(size_t i = 0; i < currentSize; i++) {
            Node *removeNode = tmp;
            tmp = tmp->next;
            delete removeNode;
        }
    }

    template<typename U>
    void push_front(U&& x) {
        if(currentSize == 0) {
            head = new Node(std::forward<U>(x), nullptr, nullptr);
            tail = head;
        }
        else {
            head->prev = new Node(std::forward<U>(x), nullptr, head);
            head = head->prev;
        }

        currentSize++;
    }

    T pop_front() {
        if(isEmpty())
            throw std::out_of_range("pop_front(): list is empty\n");

        T x = head->val;
        Node *tmp = head;
        head = head->next;

        currentSize--;
        delete tmp;
        return x;
    }

    template<typename U>
    void push_back(U&& x) {
        // if element is not found then add it to set
        if(find(x) == -1) {
            if(currentSize == 0) {
                tail = new Node(std::forward<U>(x), nullptr, nullptr);
                head = tail;
            }
            else {
                tail->next = new Node(std::forward<U>(x), tail, nullptr);
                tail = tail->next;
            }
            
            currentSize++;
        }
    }

    T pop_back() {
        if(isEmpty())
            throw std::out_of_range("pop_back(): list is empty\n");
        
        T x = tail->val;
        Node *tmp = tail;
        tail = tail->prev;

        currentSize--;
        delete tmp;
        return x;
    }

    size_t size() noexcept {
        return currentSize;
    }

    bool isEmpty() noexcept {
        return currentSize == (size_t)0;
    }

    int find(T x) {
        Node *tmp = head;
        for(size_t i = 0; i < currentSize; i++) {
            if(tmp->val == x)
                return i;
            tmp = tmp->next;
        }
        return -1;
    }

    T erase(int i) {
        if(isEmpty())
            throw std::out_of_range("erase(): list is empty\n");

        Node *tmp = head;
        for(int j = 0; j < i; j++)
            tmp = tmp->next;

        if(tmp == head)
            return pop_front();
        if(tmp == tail)
            return pop_back();
        
        T y = tmp->val;
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;

        currentSize--;
        delete tmp;
        return y;
    }

    template<typename U>
    void insert(int i, U&& x) {
        if(i == 0)
            push_front(x);
        else if((size_t)i == currentSize)
            push_back(x);
        else {
            Node *tmp1 = head;
            Node *tmp2;
            for(int j = 0; j < i - 1; j++)
                tmp1 = tmp1->next;

            tmp2 = tmp1->next;
            Node *node = new Node(std::forward<U>(x), tmp1, tmp2);
            tmp1->next = node;
            tmp2->prev = node;
            currentSize++;
        }
    }

    int remove(T x) {
        int counter = 0;
        Node *tmp = head;

        while(tmp != nullptr) {
            if(tmp->val == x) {
                if(tmp == head)
                    pop_front();
                else if(tmp == tail)
                    pop_back();
                else {
                    Node *removeNode = tmp;
                    tmp->next->prev = tmp->prev;
                    tmp->prev->next = tmp->next;

                    currentSize--;
                    delete removeNode;
                    return -1;
                }
                counter++;
            }
            tmp = tmp->next;
        }

        return counter;
    }

private:
    size_t currentSize;
    struct Node {
        Node(const T& _val, Node* _prev, Node* _next) : val(_val), prev(_prev), next(_next) {}
        T val;
        Node *prev;
        Node *next;
    } *head, *tail;
};

template<typename T>
std::ostream& operator<<(std::ostream& stream, List<T>& list) {
    auto tmp = list.head;

    for(size_t i = 0; i < list.size(); i++) {
        stream << tmp->val << ' ';
        tmp = tmp->next;
    }

    return stream;
}

#endif // LINKEDLIST_HPP