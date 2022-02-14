#include <iostream>
#include <ctime>

int main(int argc, const char *argv[]) {
    if(argc != 2) {
        std::cout << "Zla liczba argumentow\n";
        return -1;
    }

    int n = std::stoi(argv[1]);
    std::cout << n << '\n';
    srand(time(NULL));

    for(int i = 0; i < n; i++) {
        int option = std::rand();
        int mod = option % 10;

        if(mod >= 0 && mod <= 3)
            std::cout << 'A' << (std::rand() % 1000000) + 1 << '\n';
        else if(mod >= 4 && mod <= 7)
            std::cout << 'D' << '\n';
        else
            std::cout << 'S' << '\n';
    }
}