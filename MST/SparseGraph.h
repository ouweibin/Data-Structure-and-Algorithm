
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : SparseGraph.h
*   Last Modified : 2019-10-01 14:17
*   Describe      :
*
*******************************************************/

#ifndef _SPARSEGRAPH_H
#define _SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cstddef>
#include <cassert>
#include "Edge.h"

template <typename Weight>
class SparseGraph {
public:
    SparseGraph(bool directed, int vertexes) :
        directed(directed),
        vertexes(vertexes),
        edges(0) {
        for(int i = 0; i < vertexes; ++i) {
            lists.push_back(std::vector<Edge<Weight>*>());
        }
    }

    ~SparseGraph() {
        for(int i = 0; i < vertexes; ++i) {
            for(size_t j = 0; j < lists[i].size(); ++j) {
                delete lists[i][j];
            }
        }
    }

    int V() { return vertexes; }
    int E() { return edges; }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < vertexes);
        assert(w >= 0 && w < vertexes);

       for(size_t i = 0; i < lists[v].size(); ++i) {
            if(lists[v][i]->another(v) == w)
                return true;
        }
        return false;
    }

    void addEdge(int v, int w, Weight weight) {
        assert(v >= 0 && v < vertexes);
        assert(w >= 0 && w < vertexes);

        // 不考虑平行边，降低复杂度
        lists[v].push_back(new Edge<Weight>(v, w, weight));
        if(v != w && !directed) {  // 处理自环边
            lists[w].push_back(new Edge<Weight>(w, v, weight));
        }

        edges++;
    }

    void show() {
        std::cout << "SparseGraph with weight:" << std::endl;
        for(int i = 0; i < vertexes; ++i) {
            std::cout << '\t' << "vertex " << i << ":\t";
            for(size_t j = 0; j < lists[i].size(); ++j) {
                std::cout << "(to:"<< lists[i][j]->w() << ",wt:" << lists[i][j]->wt() << ")\t";
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

        Edge<Weight>* begin() {
            index = 0;
            if(graph.lists[v].size() > 0) {
                return graph.lists[v][index];
            }
            return nullptr;
        }
        Edge<Weight>* next() {
            index++;
            if(index < graph.lists[v].size()) {
                return graph.lists[v][index];
            }
            return nullptr;
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
    std::vector<std::vector<Edge<Weight>*>> lists;  // 使用vector代替list
};

#endif // _SPARSEGRAPH_H

