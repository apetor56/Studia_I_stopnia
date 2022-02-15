#ifndef POINTS_HPP
#define POINTS_HPP

#include "ArrayList.hpp"
#include <limits>

int dim;

void setDim(int n) {
    dim = n;
}

template<typename T>
class Point {
public:
    Point() {}
    
    T& operator[](int i) {
        return coords[i];
    }
    
private:
    ArrayList<T> coords;

    template<typename U>
    friend std::istream& operator>>(std::istream& stream, Point<U>& point);

    template<typename U>
    friend std::ostream& operator<<(std::ostream& stream, Point<U>& point);
};

template<typename T>
std::istream& operator>>(std::istream& stream, Point<T>& point) {
        for(int i = 0; i < dim; i++) {
            stream >> point[i];
        }

        return stream;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, Point<T>& point) {
        stream << '(';
        for(int i = 0; i < dim - 1; i++) {
            stream << point[i] << ", ";
        }
        stream << point[dim - 1] << ')';

        return stream;
}

#endif // POINTS_HPP