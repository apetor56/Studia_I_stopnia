#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <bitset>
#include <optional>
#include <vector>
#include <fstream>

const std::string path_to_dir = "../graph/";

template<int capacity>
class Graph {
public:
    Graph() : _size(0) {
        for(int i = 0; i < capacity; i++) {
            for(int j = 0; j < capacity; j++) {
                edges[i][j] = INT_MAX;
            }
        }
    }

    Graph(const Graph&) = delete;

    Graph& operator=(const Graph&) = delete;

    void addVertex() {
        vertexInit[_size] = true;
        _size++;
    }

    std::optional<int> getVertex(unsigned int i) {
        if(vertexInit[i] == true) {
            return vertices[i];
        }

        return {};
    }

    void setVertex(unsigned int i, int value) {
        if(vertexInit[i] == true) {
            vertices[i] = value;
        }
    }

    void removeVertex(unsigned int i) {
        for(int j = 0; j < capacity; j++) {
            edges[i][j] = INT_MAX;
        }
        vertexInit[i] = false;
        _size--;
    }

    void addEdge(unsigned int i, unsigned int j) {
        if(vertexInit[i] & vertexInit[j]) {
            edges[i][j] = 1;
            edges[j][i] = 1;
        }
    }

    std::optional<int> getEdge(unsigned int i, unsigned int j) {
        if(vertexInit[i] & vertexInit[j]) {
            return edges[i][j];
        }

        return {};
    }

    void setEdge(int value, unsigned int i, unsigned int j) {
        if(vertexInit[i] & vertexInit[j]) {
            edges[i][j] = value;
            edges[j][i] = value;
        }
    }

    void removeEdge(unsigned int i, unsigned int j) {
        if(vertexInit[i] & vertexInit[j]) {
            edges[i][j] = INT_MAX;
            edges[j][i] = INT_MAX;
        }
    }

    bool adjacent(unsigned int i, unsigned int j) {
        if(edges[i][j] != INT_MAX || edges[i][j] != INT_MAX) {
            return true;
        }

        return false;
    }

    std::vector<int> neighbours(unsigned int i) {
        std::vector<int> vec;
        for(int j = 0; j < capacity; j++) {
            if(edges[i][j] != INT_MAX && vertexInit[j] == true) {
                vec.push_back(edges[i][j]);
            }
        }

        return vec;
    }

    void saveToImage(std::string&& name) {
        std::fstream file;
        file.open(path_to_dir + name + ".dot", std::fstream::out | std::fstream::trunc);

        if(!file) {
            std::cerr << "failed to open file\n";
            return;
        }

        file << "digraph A {\n";
        for(int i = 0; i < capacity; i++) {
            for(int j = 0; j < capacity; j++) {
                if(edges[i][j] != INT_MAX) {
                    file << '\t' << i << " -> " << j << " [label = " << "\"" << i << j << "\"];\n";
                }
            }
        }
        file << "}";

        file.close();
    }

private:
    int vertices[capacity] {};
    int edges[capacity][capacity];
    int _size;
    std::bitset<capacity> vertexInit;
};

#endif // GRAPH_HPP