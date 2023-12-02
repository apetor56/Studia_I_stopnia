#include <iostream>
#include <ctime>
#include "Set.hpp"

int main() {
    Set<char> set_char;
    set_char.put('a');
    set_char.put('z');

    std::cout << set_char << '\n';

    Set<std::string> set_string;
    set_string.put("aa");
    set_string.put("ab");
    set_string.put("zz");
    set_string.put("bb");

    std::cout << set_string << '\n';

    Set<int> set_int;
    set_int.setRange(-20, 30, 2);

    for(int i = -20; i <= 30; i += 2) {
        set_int.put(i);
    }

    std::cout << set_int << '\n';
}