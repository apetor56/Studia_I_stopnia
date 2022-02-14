#include <iostream>
#include "BinaryTree.hpp"

int main(void) {
    BinaryTree<int> tree;

    int n;
    int x;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> x;
        tree.insert(x);
    }

    std::cout << tree.size() << ' ' << tree.depth() << ' ' << tree.minimum() << ' ' << tree.maximum() << '\n';
    tree.preorder(tree.getRoot());
    
    for(int i = 1; i <= 9; i++) {
        if(tree.searchRecursive(i, tree.getRoot()) != nullptr)
            std::cout << "Yes\n";
        else 
            std::cout << "No\n";
    }
}