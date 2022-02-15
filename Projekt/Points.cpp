#include <iostream>
#include <fstream>
#include "Base.hpp"

int main(int argc, const char *argv[]) {
    const char *fileName = argv[1];
    int dim;
    int n;

    std::fstream file(fileName);
    if(!file.good()) {
        std::cout << "Wystąpił błąd przy otwieraniu pliku\n";
        return -1;
    }

    file >> dim >> n;
    PointsBase<int> base(dim);

    Point<int> p;
    for(int i = 0; i < n; i++) {
        file >> p;
        base.addPoint(p);
    }

    Point<int> p2;

    std::cout << "Proszę wprowadzić współrzędne punktu (" << dim << "-wymiarowy): \n";
    std::cout.precision(5);
    while(file >> p2) {
        std::cout << p2 << '\n';

        Point<int> nearest;
        nearest = base.nearestNeighbor(p2);
        std::cout << "Najbliższy dystans: " << base.distance(p2, nearest) << "\n\n";
        std::cout << "Proszę wprowadzić współrzędne punktu (" << dim << "-wymiarowy): \n";
    }
    

    file.close();
}