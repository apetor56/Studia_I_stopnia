#include <iostream>
#include <ctime>

int main(int argc, const char *argv[]) {
    std::ios_base::sync_with_stdio(false);
    if(argc != 3) {
        std::cout << "Nieodpowiednia liczba argumentow\n";
        return -1;
    }

    int n = std::stoi(argv[1]);
    int max = std::stoi(argv[2]);

    srand(time(NULL));
    for(int i = 0; i < n; i++)
        std::cout << rand() % max + 1 << '\n';
}