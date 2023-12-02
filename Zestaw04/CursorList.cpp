#include <iostream>
#include "CursorList.hpp"

int main() {
    CursorList<int> list;
    
    int n, x;
    char option;     
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        std::cin >> option;
        try {
            switch(option) {
            case 'F':
                std::cin >> x;
                list.push_front(x);
                break;

            case 'B':
                std::cin >> x;
                list.push_back(x);
                break;

            case 'f':
                if(list.isEmpty())
                    std::cout << "EMPTY\n";
                else
                    std::cout << list.pop_front() << '\n';
                break;

            case 'b':
                if(list.isEmpty())
                    std::cout << "EMPTY\n";
                else
                    std::cout << list.pop_back() << '\n';
                break;

            case 'R':
                int y;
                std::cin >> x >> y;
                if(list.find(x) == -1)
                    std::cout << "FALSE\n";
                else {
                    int pos = list.find(x);
                    list.erase(pos);
                    list.insert(pos, y);
                    std::cout << "TRUE\n";
                }
                break;

            case 'S':
                std::cout << list.size() << '\n';
                break;
            }
        }
        catch(std::out_of_range& e) {
            std::cout << e.what();
        }
    }
}