#ifndef SETSIMPLE_HPP
#define SETSIMPLE_HPP

#include <iostream>

static uint32_t capacity;
uint32_t unionComplexity;
uint32_t intersectionComplexity;

class SetSimple {
public:
    SetSimple() : data(new bool[2 * capacity]()) {}

    SetSimple(uint32_t size) : data(new bool[size]()) {
        capacity = size;
    }

    ~SetSimple() {
        delete[] data;
    }

    friend std::ostream& operator<< (std::ostream& stream, const SetSimple& A);

    static SetSimple setUnion(const SetSimple& A, const SetSimple& B) {
        SetSimple result;
        unionComplexity = 0;

        for(uint32_t i = 0; i < capacity; i++) {
            if(A.get(i) | B.get(i)) {
                result.put(i);
                unionComplexity++;
            }
        }

        return result;
    }

    static SetSimple intersection(const SetSimple& A, const SetSimple& B) {
        SetSimple result;
        intersectionComplexity = 0;

        for(uint32_t i = 0; i < capacity; i++) {
            if(A.get(i) & B.get(i)) {
                result.put(i);
                intersectionComplexity++;
            }
        }

        return result;
    }

    SetSimple operator/ (const SetSimple& B) {
        SetSimple result;

        for(uint32_t i = 0; i < capacity; i++) {
            if(this->get(i) & !B.get(i)) {
                result.put(i);
            }
        }

        return result;
    }

    bool operator== (const SetSimple& B) {
        for(uint32_t i = 0; i < capacity; i++) {
            if(this->get(i) != B.get(i)) {
                return false;
            }
        }

        return true;
    }


    void put(uint32_t x) {
        if(x > capacity) {
            throw std::out_of_range("put(): out of range\n");
        }

        if(get(x) == false) {
            data[x] = true;
        }
        /* else {
            std::cout << x << " is already in a set.\n";
        } */
    }

    void erase(uint32_t x) {
        if(x > capacity) {
            throw std::out_of_range("put(): out of range\n");
        }

        data[x] = false;
    }

    bool get(uint32_t i) const {
        if(i > capacity) {
            throw std::out_of_range("put(): out of range\n");
        }

        return data[i];
    }

private:
    bool *data;
};

std::ostream& operator<< (std::ostream& stream, const SetSimple& A) {
    for(uint32_t i = 0; i < capacity; i++) {
        if(A.get(i) == true) {
            stream << i << ' ';
        }
    }

    return stream;
}

#endif // SETSIMPLE_HPP