#ifndef KDKDPOINTS_HPP
#define KDKDPOINTS_HPP

#include "ArrayList.hpp"
#include <limits>

int dim;

void setDim(int n) {
    dim = n;
}

template<typename T>
class KDPoint {
public:

    KDPoint() : left(nullptr), right(nullptr), up(nullptr) {}

    T& operator[](int i) {
        return coords[i];
    }

    int getSize() {
        return dim;
    }
    
    KDPoint *left, *right, *up;
    ArrayList<T> coords;

    template<typename U>
    friend std::istream& operator>>(std::istream& stream, KDPoint<U>& KDPoint);

    template<typename U>
    friend std::ostream& operator<<(std::ostream& stream, KDPoint<U>& KDPoint);
};

template<typename T>
std::istream& operator>>(std::istream& stream, KDPoint<T>& point) {
        for(int i = 0; i < dim; i++) {
            stream >> point[i];
        }

        return stream;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, KDPoint<T>& point) {
        stream << '(';
        for(int i = 0; i < dim - 1; i++) {
            stream << point[i] << ", ";
        }
        stream << point[dim - 1] << ')';

        return stream;
}

#endif // KDPOINTS_HPP