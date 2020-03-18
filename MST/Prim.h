
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : Prim.h
*   Last Modified : 2019-10-04 12:03
*   Describe      :
*
*******************************************************/

#ifndef  _PRIM_H
#define  _PRIM_H

#include <vector>
#include <cassert>

#include "Edge.h"
#include "IndexMinHeap.h"

template <typename Graph, typename Weight>
class Prim {
public:
    Prim(Graph& graph) :
        graph(graph),
        ipq(IndexMinHeap<double>(graph.V())),
        marked(std::vector<bool>(graph.V(), false)),
        edgeTo(std::vector<Edge<Weight>*>(graph.V(), nullptr)),
        mstWeight(0) {
        assert(graph.E() >= 1);
        mst.clear();

        // Prim
        visit(0);
        while(!ipq.empty()) {
            int v = ipq.extractMinIndex();
            assert(edgeTo[v]);
            mst.push_back(*edgeTo[v]);
            visit(v);
        }

        for(size_t i = 0; i < mst.size(); ++i) {
            mstWeight += mst[i].wt();
        }
    }

    std::vector<Edge<Weight>> mstEdges() {
        return mst;
    }

    Weight result() {
        return mstWeight;
    }


private:
    void visit(int v) {
        assert(!marked[v]);
        marked[v] = true;

        typename Graph::Iterator iter(graph, v);
        for(Edge<Weight>* p = iter.begin(); !iter.end(); p = iter.next()) {
            int w = p->another(v);
            if(!marked[w]) {
                if(!edgeTo[w]) {
                    edgeTo[w] = p;
                    ipq.insert(w, p->wt());
                }
                else if(p->wt() < edgeTo[w]->wt()) {
                    edgeTo[w] = p;
                    ipq.change(w, p->wt());
                }
            }
        }
    }

private:
    Graph& graph;
    std::vector<Edge<Weight>> mst;
    
    IndexMinHeap<Weight> ipq;
    std::vector<bool> marked;
    std::vector<Edge<Weight>*> edgeTo;

    Weight mstWeight;
};

#endif // _PRIM_H

