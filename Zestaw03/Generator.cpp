#include <iostream>
#include <ctime>

int main(int argc, const char *argv[]) {
    int n = std::stoi(argv[1]);
    std::cout << n;

    srand(time(NULL));
    int random;
    int option;

    for(int i = 0; i < n; i++) {
        random = rand() % 1000;
        option = random % 6;
        switch(option) {
        case 0:
            std::cout << 'F' << random;
            break;

        case 1:
            std::cout << 'B' << random;
            break;

        case 2:
            std::cout << 'f';
            break;

        case 3:
            std::cout << 'b';
            break;

        case 4:
            std::cout << 'R' << random << rand() % 1000;
            break;

        case 5:
            std::cout << 'S';
            break; 
        }
    }
}