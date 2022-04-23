#include <iostream>

int main(int argc, const char *argv[]) {
    if(argc != 2) {
        std::cerr << "enter positive number (e.g. \"Generator.exe 10\"\n";
        return -1;
    }

    int n = std::atoi(argv[1]);

    std::string s = "abcdefghijklmnoprstuvwxyzABCDEFGHIJKLMNOPQRSTUWVXYZ0123456789\n";
    for(int j = 0; j < n; j++) {
        std::string tmp;

        for(int i = 0; i < 50; i++) {
            tmp += s[rand() % (s.size() - 1)];
        }

        std::cout << tmp << '\n';
    }
}