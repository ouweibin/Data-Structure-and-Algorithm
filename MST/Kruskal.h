
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : Kruskal.h
*   Last Modified : 2019-10-04 12:31
*   Describe      :
*
*******************************************************/

#ifndef  _KRUSKAL_H
#define  _KRUSKAL_H

#include <iostream>
#include <vector>

#include "Edge.h"
#include "MinHeap.h"
#include "UnionFind.h"

template <typename Graph, typename Weight>
class Kruskal {
public:
    Kruskal(Graph& graph) :
        mstWeight(0) {
        mst.clear();

        MinHeap<Edge<Weight>> pq(graph.E());
        for(int i = 0; i < graph.V(); ++i) {
            typename Graph::Iterator iter(graph, i);
            for(Edge<Weight>* p = iter.begin(); !iter.end(); p = iter.next()) {
                if(p->v() < p->w()) {
                    pq.insert(*p);
                }
            }
        }

        UnionFind uf(graph.V());
        while(!pq.empty() && mst.size() < graph.V()-1) {
            Edge<Weight> e = pq.extractMin();
            if(uf.isConnected(e.v(), e.w()))
                continue;

            mst.push_back(e);
            uf.unionElements(e.v(), e.w());
        }

        for(size_t i = 0; i < mst.size(); ++i) {
            mstWeight += mst[i].wt();
        }
    }

    ~Kruskal() { }

    std::vector<Edge<Weight>> mstEdges() {
        return mst;
    }

    Weight result() {
        return mstWeight;
    }

private:
    std::vector<Edge<Weight>> mst;
    Weight mstWeight;
};

#endif // _KRUSKAL_H


