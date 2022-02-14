#ifndef CURSORLIST_HPP
#define CURSORLIST_HPP

#include <iostream>
const uint32_t MAXSIZE = 10000;

template<typename T>
class CursorList {
public:
    CursorList() : m_List(new Node[MAXSIZE]), head(0), tail(0),
                     m_Size(0), spare(0) {
        for(uint32_t i = 0; i < MAXSIZE - 1; i++) {
            m_List[i].next = i + 1;
        }
    }
    
    ~CursorList() {
        delete[] m_List;
    }

    CursorList(const CursorList& other) {
        head = other.head;
        tail = other.tail;
        spare = other.spare;
        m_Size = other.m_Size;

        m_List = new Node[MAXSIZE];
        for(int i = 0; i < MAXSIZE; i++)
            m_List[i] = other.m_List[i];
    }

    CursorList& operator=(const CursorList& other) {
        head = other.head;
        tail = other.tail;
        spare = other.spare;
        m_Size = other.m_Size;

        m_List = new Node[MAXSIZE];
        for(int i = 0; i < MAXSIZE; i++)
            m_List[i] = other.m_List[i];

        return *this;
    }

    CursorList(CursorList&& other) {
        head = other.head;
        tail = other.tail;
        spare = other.spare;
        m_Size = other.m_Size;

        m_List = other.m_List;
        other.m_List = nullptr;
        other.m_Size = 0;
    }

    CursorList& operator=(CursorList&& other) {
        head = other.head;
        tail = other.tail;
        spare = other.spare;
        m_Size = other.m_Size;

        m_List = other.m_List;
        other.m_List = nullptr;
        other.m_Size = 0;

        return *this;
    }

    template<typename U>
    void push_front(U&& x) {
        if(m_Size == MAXSIZE)
            throw std::out_of_range("push_front(): out of range\n");

        uint32_t nextSpare = m_List[spare].next;
        m_List[spare].element = std::forward<U>(x);
        m_List[spare].next = head;
        head = spare;
        spare = nextSpare;

        m_Size++;
    }

    T pop_front() {
        if(m_Size == 0)
            throw std::out_of_range("pop_front(): out of range\n");

        uint32_t nextHead = m_List[head].next;
        T value = m_List[head].element;

        m_List[head].next = spare;
        spare = head;
        head = nextHead;

        m_Size--;
        if(m_Size == 0) {
            head = spare;
            tail = spare;
        }
        return value;
    }

    template<typename U>
    void push_back(U&& x) {
        if(m_Size == MAXSIZE)
            throw std::out_of_range("push_back(): out of range\n");
        
        uint32_t nextSpare = m_List[spare].next;
        m_List[tail].next = spare;

        tail = spare;
        m_List[tail].element = std::forward<U>(x);
        m_List[tail].next = nextSpare;
        spare = nextSpare;

        m_Size++;
    }

    T pop_back() {
        if(m_Size == 0)
            throw std::out_of_range("pop_back(): out of range\n");

        if(m_Size == 1)
            return pop_front();

        Node tmp = m_List[head];
        uint32_t index = head;
        for(uint32_t i = 0; i < m_Size - 2; i++) {
            index = tmp.next;
            tmp = m_List[index];
        }

        T value = m_List[tail].element;
        m_List[tail].next = spare;
        spare = tail;
        tail = index;        

        m_Size--;
        return value;
    }

    uint32_t size() {
        return m_Size;
    }

    bool isEmpty() {
        return m_Size == 0;
    }

    void clear() {
        delete[] m_List;
    }

    int find(T x) {
        Node tmp = m_List[head];
        for(uint32_t i = 0; i < m_Size; i++) {
            if(tmp.element == x)
                return i;
            tmp = m_List[tmp.next];
        }
        return -1;
    }

    T erase(uint32_t pos) {

        if(pos == 0)
            return pop_front();
        else if(pos == m_Size - 1)
            return pop_back();
        else {
            if(m_Size == 0)
                throw std::out_of_range("erase(): out of range\n");
            
            Node tmp = m_List[head];
            uint32_t indx = head;
            for(uint32_t i = 0; i < pos - 1; i++) {
                indx = tmp.next;
                tmp = m_List[indx];
            }

            uint32_t index = tmp.next;
            T value = m_List[index].element;
            uint32_t newNext = m_List[index].next;
            m_List[indx].next = newNext;

            uint32_t prevSpare = spare;
            spare = index;
            m_List[tail].next = spare;
            m_List[index].next = prevSpare;
            
            m_Size--;
            return value;
        }
    }

    template<typename U>
    void insert(uint32_t pos, U&& x) {
        if(m_Size == MAXSIZE)
            throw std::out_of_range("insert(): out of range\n");

        if(pos == 0) {
            push_front(x);
        }
        else {
            Node tmp = m_List[head];
            uint32_t index = head;
            for(uint32_t i = 0; i < pos - 1; i++) {
                index = tmp.next;
                tmp = m_List[tmp.next];
            }

            uint32_t nextSpare = m_List[spare].next;
            m_List[spare].element = std::forward<U>(x);
            m_List[spare].next = tmp.next;
            m_List[index].next = spare;
            spare = nextSpare;
            m_Size++;
        }
    }

    uint32_t remove(T x) {
        uint32_t counter = 0;
        uint32_t index = 0;
        Node tmp = m_List[head];

        for(uint32_t i = 0; i < m_Size; i++) {
            if(tmp.element == x) {
                index = find(x);
                erase(index);
                counter++;
            }
            tmp = m_List[tmp.next];
        }

        return counter;
    }

private:
    struct Node {
        T element;
        uint32_t next;
    } *m_List;

    uint32_t head, tail;
    uint32_t m_Size;
    int spare;
};

#endif // CURSORLIST_HPP