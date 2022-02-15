#include <iostream>
#include <fstream>
#include <cstring>
#include "KDBase.hpp"

int main(int argc, const char *argv[]) {
    if(argc < 2) {
        std::cout << "Proszę wprowadzić odpowiednią liczbę argumetnów\n";
    }

    const char *fileName = argv[1];
    int dim;
    int n;

    std::fstream file(fileName);
    if(!file.good()) {
        std::cout << "Wystąpił błąd przy otwieraniu pliku\n";
        return -1;
    }

    file >> dim >> n;
    KDBase<int> base(dim);

    KDPoint<int> p;
    for(int i = 0; i < n; i++) {
        file >> p;
        base.addPoint(p);
    }

    KDPoint<int> p2;

    std::cout << "Proszę wprowadzić współrzędne punktu (" << dim << "-wymiarowy): \n";
    std::cout.precision(5);
    while(file >> p2) {
        std::cout << p2 << '\n';
        KDPoint<int> *nearest;
        nearest = base.nearestNeighbor(base.getRoot(), p2, 0);

        if(argc == 3 && !strcmp(argv[2], "-test")) {
            std::cout << "Najbliższy dystans: " << base.distance(p2, *nearest) << "\n\n";
        }
        else {
            std::cout << "Najbliższy punkt: " << *nearest << "\n\n";
        }

        std::cout << "Proszę wprowadzić współrzędne punktu (" << dim << "-wymiarowy): \n";
    }
}