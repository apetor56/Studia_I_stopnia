#ifndef DICT_HPP
#define DICT_HPP

#include <utility>
#include "LinkedList.hpp"
#include <limits>

const int SIZE = 32;


template<typename K, typename V>
class Dict {
public:
    using Pair = std::pair<K, V>;
    using NodePtr = Node<Pair> *;

    Dict() : tab(new List<Pair>[SIZE]), classes(0), 
                minClass(std::numeric_limits<uint32_t>::max()), maxClass(0) {}

    ~Dict() {
        delete[] tab;
    }

    void clear() {
        for(int i = 0; i < SIZE; i++)
            tab[i].clear();
        
        pairs = 0;
        classes = 0;
        minClass = 0;
        maxClass = 0;
    }

    bool find(const K& key) {
        size_t index = hash_fun(key);
        NodePtr tmp = tab[index].getHead();

        for(size_t i = 0; i < tab[index].size(); i++) {
            if(tmp->val.first == key)
                return true;

            tmp = tmp->next;
        }

        return false;
    }

    size_t hash_fun(K key) {
        size_t hash = 0;
        for(size_t i = 1; i < key.size(); i++) {
            hash += key[i];
        }
        
        return hash % SIZE;
    }

    bool insert(const Pair& pair) {
        size_t index = hash_fun(pair.first);

        if(tab[index].find(pair) == -1) {
            tab[index].push_back(pair);
            pairs++;

            return true;
        }

        return false;
    }

    V& operator[](const K& key) { 
        if(find(key)) {
        size_t index = hash_fun(key);
        NodePtr tmp = tab[index].getHead();

            for(size_t i = 0; i < tab[index].size(); i++) {
                if(tmp->val.first == key) {
                    return tmp->val.second;
                }
                
                tmp = tmp->next;
            }
        }
        throw std::out_of_range("Didn't find key\n");
    }

    bool erase(const K& key) {
        if(find(key)) {
            size_t index = hash_fun(key);
            Pair pair(key, this->operator[](key));
            tab[index].remove(pair);

            pairs--;
            return true;
        }

        return false;
    }

    bool isEmpty() {
        for(int i = 0; i < SIZE; i++)
            if(tab[i].size() > 0) {
                return false;   
            }

        return true;
    }

    size_t size() {
        return pairs;
    }

    void buckets() {
        classes = 0; 
        for(uint32_t i = 0; i < SIZE; i++) {
            if(tab[i].size() != 0) {
                classes++;
                
                if(tab[i].size() > maxClass)
                    maxClass = tab[i].size();

                if(tab[i].size() < minClass)
                    minClass = tab[i].size();
            }

        }
        
        std::cout << "# " << pairs << ' ' << classes << ' ' << minClass << ' ' << maxClass << '\n';
    }

private:
    List<Pair> *tab;
    uint32_t pairs;
    uint32_t classes;
    uint32_t minClass, maxClass;
};

#endif // DICT_HPP