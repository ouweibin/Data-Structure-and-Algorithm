
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : SparseGraph.h
*   Last Modified : 2019-09-30 15:22
*   Describe      :
*
*******************************************************/

#ifndef _SPARSEGRAPH_H
#define _SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cstddef>
#include <cassert>

class SparseGraph {
public:
    SparseGraph(bool directed, int vertexes) :
        directed(directed),
        vertexes(vertexes),
        edges(0) {
        for(int i = 0; i < vertexes; ++i) {
            lists.push_back(std::vector<int>());
        }
    }

    ~SparseGraph() { }

    int V() { return vertexes; }
    int E() { return edges; }
    void setV(int vertexes) { this->vertexes = vertexes; }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < vertexes);
        assert(w >= 0 && w < vertexes);

       for(size_t i = 0; i < lists[v].size(); ++i) {
            if(lists[v][i] == w)
                return true;
        }
        return false;
    }

    void addEdge(int v, int w) {
        assert(v >= 0 && v < vertexes);
        assert(w >= 0 && w < vertexes);

        // 不考虑平行边，降低复杂度
        // if(hasEdge(v, w))
        //     return;
 
        lists[v].push_back(w);
        if(v != w && !directed) {  // 处理自环边
            lists[w].push_back(v);
        }

        edges++;
    }

    void show() {
        std::cout << "SparseGraph :" << std::endl;
        for(int i = 0; i < vertexes; ++i) {
            std::cout << "    " << "vertex " << i << ": ";
            for(size_t j = 0; j < lists[i].size(); ++j) {
                std::cout << lists[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    class Iterator {
    public:
        Iterator(SparseGraph& graph, int v) :
            graph(graph),
            v(v),
            index(0) { }

        int begin() {
            index = 0;
            if(graph.lists[v].size() > 0) {
                return graph.lists[v][index];
            }
            return -1;
        }
        int next() {
            index++;
            if(index < graph.lists[v].size()) {
                return graph.lists[v][index];
            }
            return -1;
        }
        bool end() { return index >= graph.lists[v].size(); }

    private:
        SparseGraph& graph;
        int v;
        size_t index;
    };

private:
    bool directed;
    int vertexes;
    int edges;
    std::vector<std::vector<int>> lists;  // 使用vector代替list
};

#endif // _SPARSEGRAPH_H

