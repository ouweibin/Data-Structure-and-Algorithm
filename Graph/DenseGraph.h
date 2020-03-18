
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : DenseGraph.h
*   Last Modified : 2019-09-30 15:22
*   Describe      :
*
*******************************************************/

#ifndef _DENSEGRAPH_H
#define _DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

class DenseGraph {
public:
    DenseGraph(bool directed, int vertexes) :
        directed(directed),
        vertexes(vertexes),
        edges(0) {
        for(int i = 0; i < vertexes; ++i) {
            matrix.push_back(std::vector<bool>(vertexes, false));
        }
    }

    ~DenseGraph() { }

    int V() { return vertexes; }
    int E() { return edges; }
    void setV(int vertexes) { this->vertexes = vertexes; }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < vertexes);
        assert(w >= 0 && w < vertexes);
        return matrix[v][w];
    }

    void addEdge(int v, int w) {
        assert(v >= 0 && v < vertexes);
        assert(w >= 0 && w < vertexes);

        if(hasEdge(v, w))  // 不考虑平行边
            return;

        matrix[v][w] = true;
        if(!directed) {
            matrix[w][v] = true;
        }

        edges++;
    }

    void show() {
        std::cout << "DenseGraph :" << std::endl;
        for(int i = 0; i < vertexes; ++i) {
            std::cout << "    ";
            for(int j = 0; j < vertexes; ++j) {
                std::cout << matrix[i][j] << " ";
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

        int begin() { index = -1; return next(); }
        int next() { // 找到邻边就返回
            for(index += 1; index < graph.V(); ++index) {
                if(graph.matrix[v][index]) {
                    return index;
                }
            }
            return -1;
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
    std::vector<std::vector<bool>> matrix;
};

#endif // _DENSEGRAPH_H

