#ifndef BASE_HPP
#define BASE_HPP

#include "Points.hpp"

template<typename T>
class PointsBase {
public:
    PointsBase(int n) {
        dim = n;
    }

    void addPoint(const Point<T>& point) {
        base.push_back(point);
    }

    double distance(Point<T> p1, Point<T> p2) {
        double dis = 0.0;
        for(int i = 0; i < dim; i++) {
            dis += (p1[i] - p2[i]) * (p1[i] - p2[i]);
        }

        return dis;
    }

    Point<T>& nearestNeighbor(const Point<T>& p) {
        if(base.size() == 0)
            throw std::out_of_range("empty\n");
        
        int nearestIndex = 0;
        double minDistance = std::numeric_limits<double>::max();
        double currDistance;

        for(int i = 0; i < (int)base.size(); i++) {
            currDistance = distance(p, base[i]);

            if(minDistance > currDistance) {
                minDistance = currDistance;
                nearestIndex = i;
            }
        }

        return base[nearestIndex];
    }

    Point<T>& operator[](int i) {
        return base[i];
    }

private:
    ArrayList<Point<T>> base;
};

#endif // BASE_HPP