#include <iostream>
#include <time.h>

int main(int argc, const char *argv[]) {
    if(argc != 4) {
        std::cout << "Proszę wprowadzić odpowiednią liczbę argumentów\n";
        return -1;
    }

    int dim = std::stoi(argv[1]);
    int n = std::stoi(argv[2]);
    int max = std::stoi(argv[3]);

    srand(time(NULL));
    std::cout << dim << ' ' << n << "\n\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < dim; j++) {
            std::cout << rand() % max << ' ';
        }
        std::cout << '\n';
    }

    std::cout << '\n';

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < dim; j++) {
            std::cout << rand() % max << ' ';
        }
        std::cout << '\n';
    }
}