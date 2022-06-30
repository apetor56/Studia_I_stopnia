#ifndef BINARYHEAP_HPP
#define BINARYHEAP_HPP

#include <vector>
#include <optional>

constexpr unsigned int MAXSIZE = 1000;

template<typename T>
class BinaryHeap {
public:
    template<typename U>
    friend std::ostream& operator<<(std::ostream& stream, BinaryHeap<U>& queue);

    struct element {
        element() = default;

        element(T _value, int _priority) : 
            value(_value), priority(_priority) {}

        bool operator<(element& other) {
            return ((this->priority) < (other.priority));
        }

        bool operator<=(element& other) {
            return ((this->priority) <= (other.priority));
        }

        T value;
        int priority;
    };

    BinaryHeap(unsigned int size = MAXSIZE) :  _size(0) {
        data.resize(size);  
    }

    BinaryHeap(const BinaryHeap& other) = delete;

    BinaryHeap& operator=(const BinaryHeap& other) = delete;

    template<typename U>
    void enqueue(U&& x) {
        if(_size == 0) {
            data[0] = x;
            _size = 1;
        }
        else {
            if(data.size() == _size) {
                throw std::out_of_range("enqueue(): out of range");
            }

            int sonIndex = _size;
            int fatherIndex = (sonIndex - 1) / 2;
            _size++;
            
            while(sonIndex > 0 && x < data[fatherIndex]) {
                data[sonIndex] = data[fatherIndex];
                sonIndex = fatherIndex;
                fatherIndex = (fatherIndex - 1) / 2;
            }

            data[sonIndex] = x;
        }
    }

    std::optional<element> dequeue() {
        if(_size != 0) {
            element root = data[0];

            _size--;
            element leaf = data[_size];

            unsigned int fatherIndex = 0;
            unsigned int sonIndex = 1;

            while(sonIndex < _size) {
                // if rigth son is lesser than left, then choose it
                if(sonIndex + 1 < _size && data[sonIndex + 1] < data[sonIndex]) {
                    sonIndex++;
                }

                if(leaf <= data[sonIndex]) {
                    break;
                }

                data[fatherIndex] = data[sonIndex];
                fatherIndex = sonIndex;
                sonIndex = 2 * sonIndex + 1;
            }

            data[fatherIndex] = leaf;
            return root;
        }

        return std::nullopt;
    }

private:
    std::vector<element> data;
    unsigned int _size;
};

template<typename T>
std::ostream& operator<<(std::ostream& stream, BinaryHeap<T>& queue) {
    for(unsigned int i = 0u; i < queue._size; i++) {
        stream << queue.data.at(i).value << ' ';
    }
    stream << '\n';

    return stream;
}

#endif //BINARYHEAP_HPP