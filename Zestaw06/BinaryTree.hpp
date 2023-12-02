#ifndef BINARY_TREE
#define BINARY_TREE

template<typename T>
struct Node {
        Node(Node *up, T key, uint32_t level, Node *left = nullptr, Node *right = nullptr) {
            this->up = up;
            this->key = key;
            this->level = level;
            this->left = left;
            this->right = right;
        }
        
        Node *up;
        T key;
        uint32_t level;
        Node *left;
        Node *right;
};

template<typename T>
class BinaryTree {
public:
    using NodePtr = Node<T> *;

    BinaryTree() : m_Size(0), m_Level(0), m_Root(nullptr) {}

    template<typename U>
    void insert(U&& x) {
        NodePtr node;
        if(m_Size == 0) {
            node = new Node<T>(nullptr, std::forward<U>(x), 1);
            m_Root = node;
        }
        else {
            NodePtr tmp = m_Root;

            while(true) {
                if(x < tmp->key) {
                    if(tmp->left != nullptr) {
                        tmp = tmp->left;
                    }
                    else {
                        tmp->left = new Node<T>(tmp, std::forward<U>(x), tmp->level + 1);
                        if(tmp->level + 1 > m_Level)
                            m_Level = tmp->level + 1;
                        
                        break;
                    }
                }
                else {
                    if(tmp->right != nullptr) {
                        tmp = tmp->right;
                    }
                    else {
                        tmp->right = new Node<T>(tmp, std::forward<U>(x), tmp->level + 1);
                        if(tmp->level + 1 > m_Level)
                            m_Level = tmp->level + 1;
                        
                        break;
                    }
                }
            }
        }
        m_Size++;
    }

    NodePtr search(T x) {
        NodePtr tmp = m_Root;
        while(tmp != nullptr) {
            if(x < tmp->key)
                tmp = tmp->left;
            else if(x > tmp->key)
                tmp = tmp->right;
            
            return tmp;
        }
        return nullptr;
    }

    NodePtr searchRecursive(T x, NodePtr node) {
        if(node != nullptr) {
            if(x < node->key)
                return searchRecursive(x, node->left);
            else if(x > node->key)
                return searchRecursive(x, node->right);
            
            return node;
        }
        return nullptr;
    }

    T minimum() {
        NodePtr tmp = m_Root;
        while(tmp->left != nullptr)
            tmp = tmp->left;
        
        return tmp->key;
    }

    T maximum() {
        NodePtr tmp = m_Root;
        while(tmp->right != nullptr)
            tmp = tmp->right;
        
        return tmp->key;
    }

    uint32_t depth() {
        return m_Level;
    }

    void preorder(NodePtr node) {
        if(node != nullptr) {
            std::cout << node->key << '\n';
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(NodePtr node) {
        if(node != nullptr) {
            inorder(node->left);
            std::cout << node->key << '\n';
            inorder(node->right);
        }
    }

    void postorder(NodePtr node) {
        if(node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            std::cout << node->key;
        }
    }

    uint32_t size() {
        return m_Size;
    }

    NodePtr getRoot() {
        return m_Root;
    }

private:
    uint32_t m_Size;
    uint32_t m_Level;
    NodePtr m_Root;
};

#endif //BINARY_TREE