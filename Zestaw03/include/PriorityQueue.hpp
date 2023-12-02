#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <vector>
#include <optional>
#include "LinkedList.hpp"

template<typename T, unsigned int maxPriority>
class PriorityQueue {
public:
    template<typename U, unsigned int max>
    friend std::ostream& operator<<(std::ostream& stream, PriorityQueue<U, max>& priorQueue);

    PriorityQueue() : size(0) {
        queue.resize(maxPriority);
    }

    void enqueue(T element, unsigned int priority) {
        queue.at(priority).push_back(element);
        size++;
    }

    std::optional<T> dequeue() {
        if(size != 0) {
            for(unsigned int i = 0u; i < maxPriority; i++) {
                if(queue.at(i).size() != 0) {
                    size--;
                    return queue.at(i).pop_front();
                }
            }
        }

        return std::nullopt;
    }

private:
    std::vector<List<T>> queue;
    unsigned int size;
};

template<typename T, unsigned int maxPriority>
std::ostream& operator<<(std::ostream& stream, PriorityQueue<T, maxPriority>& priorQueue) {    
    for(unsigned int i = 0u; i < maxPriority; i++) {
        auto& currentList = priorQueue.queue.at(i);
        if(currentList.size() != (size_t)0) {
            stream << '[' << i << "]: " << currentList << '\n';
        }
    }

    return stream;
}

#endif // PRIORITYQUEUE_HPP