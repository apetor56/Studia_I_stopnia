#include <iostream>
#include "BinaryHeap.hpp"

using el = BinaryHeap<int>::element;

int main() {
    BinaryHeap<int> queue;
    
    queue.enqueue(el(3,3));
    queue.enqueue(el(4,4));
    queue.enqueue(el(2,2));
    queue.enqueue(el(7,7));
    queue.enqueue(el(3,3));
    queue.enqueue(el(1,1));


    std::cout << queue << '\n';

    for(int i = 0; i < 6; i++) {
        std::cout << queue.dequeue().value().value << '\n';
    }
}