#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

template<typename T>
class LinkedList {
public:
    LinkedList() : currentSize(0), head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        Node *tmp = head;
        while(tmp != nullptr) {
            Node *removeNode = tmp;
            tmp = tmp->next;
            delete removeNode;
        }
    }

    LinkedList(const LinkedList<T>& other) : LinkedList() {
        Node *tmp = other.head;
        for(uint32_t i = 0; i < other.size(); i++) {
            this->put(tmp->val);

            tmp = tmp->next;
        }

        currentSize = other.currentSize;
    }

    template<typename U>
    friend std::ostream& operator<<(std::ostream& stream, const LinkedList<U>& list);

    LinkedList<T>& operator=(const LinkedList<T>& other) {
        Node *tmp = other.head;
        this->clear();

        for(uint32_t i = 0; i < other.size(); i++) {
            this->put(tmp->val);
            tmp = tmp->next;
        }

        return *this;
    }

    LinkedList<T> operator/(const LinkedList<T>& B) {
        LinkedList<T> result;
        Node *tmp = head;

        for(uint32_t i = 0; i < size(); i++) {
            if(B.find(tmp->val) == -1) {
                result.put(tmp->val);
            }
            tmp = tmp->next;
        }

        return result;
    }

    bool operator==(const LinkedList<T>& B) {

        if(this->size() != B.size()) {
            return false;
        }
        else {
            Node *tmp1 = this->head;
            Node *tmp2 = B.head;

            for(uint32_t i = 0; i < B.size(); i++) {
                if(tmp1->val != tmp2->val) {
                    return false;
                }
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
            
            return true;
        }
    }

    bool operator!=(const LinkedList<T>& B) {
        return !(*this == B);
    }

    size_t size() const {
        return currentSize;
    }

    static LinkedList<T> setUnion(const LinkedList<T>& A, const LinkedList<T>& B) {
        LinkedList<T> result = A;

        Node *tmp = B.head;
        for(uint32_t i = 0; i < B.size(); i++) {
            if(result.find(tmp->val) == -1) {
                result.put(tmp->val);
            }
            
            tmp = tmp->next;    
        }

        return result;
    }

    static LinkedList<T> intersection(const LinkedList<T>& A, const LinkedList<T>& B) {
        LinkedList<T> result;
        Node *tmp = A.head;

        for(uint32_t i = 0; i < A.size(); i++) {
            if(B.find(tmp->val) != -1) {
                result.put(tmp->val);
            }

            tmp = tmp->next;
        }
        return result;
    }

    int find(T x) const {
        Node *tmp = head;

        for(size_t i = 0; i < currentSize; i++) {
            if(tmp->val == x) {
                return i;
            }
            
            tmp = tmp->next;
        }
        return -1;
    }

    template<typename U>
    void put(U&& x) {
        if(currentSize == 0) {
            push_front(x);
            return;
        }
        else if(currentSize == 1 && find(x) == -1) {
            if(x > head->val) {
                push_back(x);
            }
            else {
                push_front(x);
            }
        }
        else if(find(x) == -1) {
            uint32_t index = 0;
            Node *tmp = head;

            for(uint32_t i = 0; i < currentSize; i++) {
                if(x > tmp->val) {
                    index++;
                    tmp = tmp->next;
                }
                else {
                    break;
                }
            }
            
            if(index == currentSize) {
                push_back(x);
            }
            else {
                insert(index, x);
            }
        }
    }

    void remove(T x) {
        Node *tmp = head;

        for(uint32_t i = 0; i < currentSize; i++) {
            if(tmp->val == x) {
                if(tmp == head) {
                    pop_front();
                }
                else if(tmp == tail) {
                    pop_back();
                }
                else {
                    Node *removeNode = tmp;
                    tmp->next->prev = tmp->prev;
                    tmp->prev->next = tmp->next;

                    currentSize--;
                    delete removeNode;
                }

                return;
            }

            tmp = tmp->next;
        }
    }

    void show() const {
        Node *tmp = head;
        for(uint32_t i = 0; i < currentSize; i++) {
            std::cout << tmp->val << ' ';
            tmp = tmp->next;
        }
        std::cout << '\n';
    }

    void clear() {
        Node *tmp = head;
        while(tmp != nullptr) {
            Node *removeNode = tmp;
            tmp = tmp->next;
            delete removeNode;
        }

        head = nullptr;
        tail = nullptr;
        currentSize = 0;
    }
    
private:
    size_t currentSize;
    struct Node {
        Node(const T& _val, Node* _prev, Node* _next) : val(_val), prev(_prev), next(_next) {}
        T val;
        Node *prev;
        Node *next;
    } *head, *tail;

    template<typename U>
    void push_front(U&& x) {
        if(head == nullptr) {
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
        // if(isEmpty())
        //     throw std::out_of_range("pop_front(): LinkedList is empty\n");

        T x = std::forward<T>(head->val);
        Node *tmp = head;
        head = head->next;

        currentSize--;
        delete tmp;
        return x;
    }

    template<typename U>
    void push_back(U&& x) {
        if(!tail) {
            tail = new Node(std::forward<U>(x), nullptr, nullptr);
            head = tail;
        }
        else {
            tail->next = new Node(std::forward<U>(x), tail, nullptr);
            tail = tail->next;
        }
        currentSize++;
    }

    T pop_back() {
        // if(isEmpty())
        //     throw std::out_of_range("pop_back(): LinkedList is empty\n");
        
        T x = std::forward<T>(tail->val);
        Node *tmp = tail;
        tail = tail->prev;
        tail->next = nullptr;

        currentSize--;
        delete tmp;
        return x;
    }

    template<typename U>
    void insert(int i, U&& x) {
        if(i == 0) {
            push_front(std::forward<U>(x));
        }
        else {
            Node *tmp1 = head;
            Node *tmp2;
            for(int j = 0; j < i - 1; j++) {
                tmp1 = tmp1->next;
            }
            
            tmp2 = tmp1->next;
            Node *node = new Node(std::forward<U>(x), tmp1, tmp2);
            tmp1->next = node;
            tmp2->prev = node;

            currentSize++;
        }
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& stream, const LinkedList<T>& list) {
    auto tmp = list.head;

    for(uint32_t i = 0; i < list.size(); i++) {
        stream << tmp->val << ' ';
        tmp = tmp->next;
    }

    return stream;
}

#endif // LINKEDLIST_HPP