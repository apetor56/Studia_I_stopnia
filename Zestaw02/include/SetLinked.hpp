#ifndef SETLINKED_HPP
#define SETLINKED_HPP

#include <cmath>
#include "LinkedList.hpp"

struct position {
    int list_position;
    int element_position;

    friend std::ostream& operator<<(std::ostream& stream, const position& pos) {
        stream << '[' << pos.list_position << ", " << pos.element_position << ']';
        return stream;
    }
};

template<typename T, unsigned int capacity>
class SetLinked {
public:
    template<typename U, uint32_t size>
    friend std::ostream& operator<<(std::ostream& stream, const SetLinked<U, size>& set);

    uint32_t hash(const T& element) {
        int tmp = static_cast<int>(std::floor(element));
        return std::abs(tmp) % capacity;
    }

    void put(const T& element) {
        uint32_t index = hash(element);
        data[index].put(element);
    }

    void remove(const T& element) {
        int index = hash(element);
        data[index].remove(element);
    }

    position find(const T& element) {
        int list_index = hash(element);
        int element_index = data[list_index].find(element);

        return {list_index, element_index};
    }

    static SetLinked<T, capacity> setUnion(const SetLinked<T, capacity>& A, const SetLinked<T, capacity>& B) {
        SetLinked<T, capacity> result;

        for(uint32_t i = 0; i < capacity; i++) {
            if(A.data[i].size() != 0 || B.data[i].size() != 0) {
                result.data[i] = LinkedList<T>::setUnion(A.data[i], B.data[i]);
            }
        }

        return result;
    }

    static SetLinked<T, capacity> setIntersection(const SetLinked<T, capacity>& A, const SetLinked<T, capacity>& B) {
        SetLinked<T, capacity> result;

        for(uint32_t i = 0; i < capacity; i++) {
            if(A.data[i].size() != 0 || B.data[i].size() != 0) {
                result.data[i] = LinkedList<T>::intersection(A.data[i], B.data[i]);
            }
        }

        return result;
    }

    SetLinked<T, capacity> operator/(const SetLinked<T, capacity>& B) {
        SetLinked<T, capacity> result;

        for(uint32_t i = 0; i < capacity; i++) {
            if(this->data[i].size() != 0 || B.data[i].size() != 0) {
                result.data[i] = this->data[i] / B.data[i];
            }
        }

        return result;
    }

    bool operator==(const SetLinked<T, capacity>& B) {
        for(uint32_t i = 0; i < capacity; i++) {
            if(this->data[i] != B.data[i]) {
                return false;
            }
        }

        return true;
    }


private:
    LinkedList<T> data[capacity];
};

template<typename T, uint32_t capacity>
std::ostream& operator<<(std::ostream& stream, const SetLinked<T, capacity>& set) {
    for(uint32_t i = 0; i < capacity; i++) {
        if(set.data[i].size() != 0) {
            stream << '[' << i << "]: " << set.data[i] << '\n';
        }
    }

    return stream;
}

#endif // SETLINEKD_HPP