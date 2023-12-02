#ifndef SET_HPP
#define SET_HPP

#include <iostream>

template<typename T>
class Set {
public:
    Set() {
        // array for letters (a, b, c, ..., z)
        if(std::is_same<char, T>::value) {
            capacity = 26;
        }

        // array for two-letter words, 26 * 26 = 676
        // (aa, ab, ac, ..., zz)
        else if(std::is_same<std::string, T>::value) {
            capacity = 676;
        }

        // default array for integers with some offset
        // (without any specification offset is equal 1)
        else {
            offset = 1;
            capacity = 100;
        }

        data = new bool[capacity]();
    }

    ~Set() {
        delete[] data;
    }

    // recreating array depending on max & min values and an offset
    // e.g. min = 1, max = 11, offset = 2
    // 1, 3, 5, 7, 9, 11
    // new array size is (11 - 1) / 2 + 1 = 6 
    void setRange(int _min, int _max, uint32_t _offset = 1) {
        min = _min;
        max = _max;
        offset = _offset;
        
        // reallocating memory for 'data' array
        capacity = (max - min) / offset + 1;
        data = new bool[capacity]();
    }


    // for char: return index in array for specific letter
    // 'a' in ASCII equals 97, so index for 'a' in array is 0
    // 'b' equals 98, so index for it is 98 - 97 = 1, and so on
    uint32_t hash(const char& element) {
        return element - 97;
    }


    // for two-letter words: lexycographical order
    // e.g. first 26 elements in array will be reserved 
    // for words that begin with 'a'.
    // for "aa" index will be (97 - 97) * 26 + (97 - 97) = 0
    // "ab": 0 + 1 = 1
    // "az": 0 + 25 = 25
    // "ba": (98 - 97) * 26 + 0 = 26, and so on
    uint32_t hash(const std::string& element) {
        return (element[0] - 97) * 26 + (element[1] - 97);
    }

    // for integer numbers:
    // e.g. -3 -1 1 3 5 7
    // index for -3: (-3 + 3) / 2 = 0
    // -1 -> (-1 + 3) / 2 = 1
    // 7 -> (7 + 3) / 2 = 5
    uint32_t hash(const int& element) {
        return (element - min) / offset;
    }

    void put(const T& element) {
        // if element isn't already in set then we can
        // put it
        if(find(element) == false) {
            data[hash(element)] = true;
        }
    }

    bool find(const T& element) {
        if(hash(element) >= capacity) {
            throw std::out_of_range("find(): out of range\n");
        }

        return data[hash(element)];
    }

    template<typename U>
    friend std::ostream& operator<<(std::ostream& stream, const Set<U>& set);

private:
    bool *data;
    int min, max;
    uint32_t offset;
    uint32_t capacity;
};

template<typename U>
std::ostream& operator<<(std::ostream& stream, const Set<U>& set) {
    // for char:
    // add 97 to array index to receive char variable
    // (under condition that data[i] == true)
    if(std::is_same<char, U>::value) {
        for(uint32_t i = 0; i < set.capacity; i++) {
            if(set.data[i] == true) {
                stream << '[' << i << "] " << (char)(97 + i) << '\n';
            }
        }
    }

    // for two-letter words:
    // for i = 0..25, char(97 + i / 26) is equal 97 ('a')
    // and char(97 + i % 26) is a..z
    else if(std::is_same<std::string, U>::value) {
        for(uint32_t i = 0; i < set.capacity; i++) {
            if(set.data[i] == true) {
                stream << '[' << i << "] " << char(97 + i / 26) << char(97 + i % 26) << '\n';
            }
        }
    }

    // for integer numbers:
    // index = (element - min) / offset
    // so element = index * offset + min;
    else {
        int value;
        for(uint32_t i = 0; i < set.capacity; i++) {
            if(set.data[i] == true) {
                value = i * set.offset + set.min;
                stream << '[' << i << "] " << value << '\n';
            }
        }
    }

    return stream;
}

#endif // SET_HPP