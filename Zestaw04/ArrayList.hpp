#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>
const int MAXSIZE = 10000;

template<typename T>
class ArrayList {
public:
    // contructor
    ArrayList() : m_List(new T[MAXSIZE]), m_Size(0) {}

    // destructor
    ~ArrayList() {
        delete[] m_List;
    }

    // copy constructor
    ArrayList(const ArrayList& other) {
        m_Size = other.m_Size;
        m_List = new T[MAXSIZE];
        for(int i = 0; i < m_Size; i++) {
            m_List[i] = other.m_List[i];
        }
    }

    // copy assignment operator
    ArrayList& operator=(const ArrayList& other) {
        m_Size = other.m_Size;
        m_List = new T[MAXSIZE];
        for(int i = 0; i < m_Size; i++) {
            m_List[i] = other.m_List[i];
        }

        return *this;
    }

    // move constructor
    ArrayList(ArrayList&& other) {
        m_Size = other.m_Size;
        m_List = other.m_List;

        other.m_List = nullptr;
        other.m_Size = 0;
    }

    // move assignment operator
    ArrayList& operator=(ArrayList&& other) {
        m_Size = other.m_Size;
        m_List = other.m_List;

        other.m_List = nullptr;
        other.m_Size = 0;

        return *this;
    }

    template<typename U>
    void push_front(U&& x) {
        if(m_Size == MAXSIZE) {
            throw std::out_of_range("push_front(): out of range\n");
        }
    
        for(uint32_t i = m_Size; i > 0; i--) {
            m_List[i] = m_List[i - 1];
        }
        m_List[0] = std::forward<U>(x);
        m_Size++;  
    }

    T pop_front() {
        if(m_Size == 0) {
            throw std::out_of_range("pop_front(): out of range\n");
        }

        T tmp = m_List[0];
        for(uint32_t i = 0; i < m_Size - 1; i++) {
            m_List[i] = m_List[i + 1];
        }
        m_Size--;

        return tmp;
    }

    template<typename U>
    void push_back(U&& x) {
        if(m_Size == MAXSIZE) {
            throw std::out_of_range("push_back(): out of range\n");
        }

        m_List[m_Size] = std::forward<U>(x);
        m_Size++;
    }

    T pop_back() {
        return m_List[--m_Size];
    }

    uint32_t size() {
        return m_Size;
    }

    bool isEmpty() {
        return m_Size == 0;
    }

    void clear() {
        delete[] m_List;
        m_Size = 0;
        m_List = new T[MAXSIZE];
    }

    T find(T x) {
        for(uint32_t i = 0; i < m_Size; i++) {
            if(m_List[i] == x)
                return i;
        }
        return -1;
    }

    T erase(uint32_t i) {
        T tmp = m_List[i];
        for(uint32_t j = i; j < m_Size - 1; j++) {
            m_List[j] = m_List[j + 1];
        }
        m_Size--;

        return tmp;
    }

    template<typename U>
    void insert(uint32_t i, U&& x) {
        if(i == (uint32_t)0) {
            push_front(x);
        }
        else {
            for(uint32_t j = m_Size - 1; j >= i; j--) {
                m_List[j + 1] = m_List[j];
            }
            m_List[i] = std::forward<U>(x);
            m_Size++;
        }
    }

    uint32_t remove(T x) {
        uint32_t pos;
        uint32_t counter = 0;
        while( (pos = find(x)) != -1 ) {
            erase(pos);
            counter++;
        }

        return counter;
    }

private:
    T *m_List;
    uint32_t m_Size;
};
#endif // ARRAYLIST_HPP