#ifndef KDBASE_HPP
#define KDBASE_HPP

#include "KDPoints.hpp"

template<typename T>
class KDBase {
public:
    KDBase(int n) : size(0), root(new KDPoint<T>()) {
        setDim(n);
    }

    void addPoint(KDPoint<T>& point) {
        if(size == 0) {
            root->coords = point.coords;
        }
        else {
            int depth = 0;
            KDPoint<T> *tmp = root;

            T pointCoord, tmpCoord;
            KDPoint<T> *parent = new KDPoint<T>;
            bool f = true;

            while(tmp != nullptr) {
                parent = tmp;
                pointCoord = point.coords[depth % dim];
                tmpCoord = tmp->coords[depth % dim];

                if(pointCoord < tmpCoord) {
                    tmp = tmp->left;
                    f = true;
                }
                else {
                    tmp = tmp->right;
                    f = false;
                }

                depth++;
            }

            tmp = new KDPoint<T>();
            tmp->coords = point.coords;

            tmp->up = parent;
            if(f == true) {
                parent->left = tmp;
            }
            else {
                parent->right = tmp;
            }
        }

        size++;
    }

    KDPoint<T>* nearestNeighbor(KDPoint<T> *root, KDPoint<T>& point, int depth) {
        if(root == nullptr) {
            return nullptr;
        }

        KDPoint<T> *nextBranch = new KDPoint<T>;
        KDPoint<T> *otherBranch = new KDPoint<T>;
        if(point[depth % dim] < (*root)[depth % dim]) {
            nextBranch = root->left;
            otherBranch = root->right;
        }
        else {
            nextBranch = root->right;
            otherBranch = root->left;
        }

        KDPoint<T> *tmp = nearestNeighbor(nextBranch, point, depth + 1);
        KDPoint<T> *best = closest(point, tmp, root);

        double dist = distance(point, *best);
        double orthoDist = point[depth % dim] - (*root)[depth % dim];

        if(dist >= orthoDist * orthoDist) {
            tmp = nearestNeighbor(otherBranch, point, depth + 1);
            best = closest(point, tmp, best);
        }

        return best;
    }

    KDPoint<T> *closest(KDPoint<T>& point, KDPoint<T> *tmp, KDPoint<T> *root) {
        if(tmp == nullptr) {
            return root;
        }

        if(root == nullptr) {
            return tmp;
        }

        double distance1 = distance(point, *tmp);
        double distance2 = distance(point, *root);

        if(distance1 < distance2) {
            return tmp;
        }

        return root;
    }

    double distance(KDPoint<T> p1, KDPoint<T> p2) {
        double dis = 0.0;
        for(int i = 0; i < dim; i++) {
            dis += (p1[i] - p2[i]) * (p1[i] - p2[i]);
        }

        return dis;
    }

    void inorder(KDPoint<T>* point) {
        if(point != nullptr) {
            inorder(point->left);
            std::cout << *point << '\n';
            inorder(point->right);
        }
    }

    KDPoint<T> *getRoot() {
        return root;
    }
private:
    int size;
    KDPoint<T> *root;
};

#endif // KDBASE_HPP