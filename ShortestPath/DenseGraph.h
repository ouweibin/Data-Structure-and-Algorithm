
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : DenseGraph.h
*   Last Modified : 2019-10-01 14:17
*   Describe      :
*
*******************************************************/

#ifndef _DENSEGRAPH_H
#define _DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

#include "Edge.h"

template <typename Weight>
class DenseGraph {
public:
    DenseGraph(bool directed, int vertexes) :
        directed(directed),
        vertexes(vertexes),
        edges(0) {
        for(int i = 0; i < vertexes; ++i) {
            matrix.push_back(std::vector<Edge<Weight>*>(vertexes, nullptr));
        }
    }

    ~DenseGraph() {
        for(int i = 0; i < vertexes; ++i) {
            for(int j = 0; j < vertexes; ++j) {
                if(matrix[i][j]) {
                    delete matrix[i][j];
                }
            }
        }
    }

    int V() { return vertexes; }
    int E() { return edges; }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < vertexes);
        assert(w >= 0 && w < vertexes);
        return matrix[v][w] != nullptr;
    }

    void addEdge(int v, int w, Weight weight) {
        assert(v >= 0 && v < vertexes);
        assert(w >= 0 && w < vertexes);

        if(hasEdge(v, w)) {  // 重置平行边
            delete matrix[v][w];
            if(!directed) {
                delete matrix[w][v];
            }
            edges--;
        }

        matrix[v][w] = new Edge<Weight>(v, w, weight);
        if(!directed) {
            matrix[w][v] = new Edge<Weight>(w, v, weight);
        }
        edges++;
    }

    void show() {
        std::cout << "DenseGraph with weight:" << std::endl;
        for(int i = 0; i < vertexes; ++i) {
            std::cout << '\t';
            for(int j = 0; j < vertexes; ++j) {
                if(matrix[i][j]) {
                    std::cout << matrix[i][j]->wt() << '\t';
                }
                else {
                    std::cout << "NULL\t";
                }
            }
            std::cout << std::endl;
        }
    }

    class Iterator {
    public:
        Iterator(DenseGraph& graph, int v) :
            graph(graph),
            v(v),
            index(-1) { }

        Edge<Weight>* begin() { index = -1; return next(); }
        Edge<Weight>* next() { // 找到邻边就返回
            for(index += 1; index < graph.V(); ++index) {
                if(graph.matrix[v][index]) {
                    return graph.matrix[v][index];
                }
            }
            return nullptr;
        }
        bool end() { return index >= graph.V(); }

    private:
        DenseGraph& graph;
        int v;
        int index;
    };

private:
    bool directed;
    int vertexes;
    int edges;
    std::vector<std::vector<Edge<Weight>*>> matrix;
};

#endif // _DENSEGRAPH_H

