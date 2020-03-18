
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : LazyPrim.h
*   Last Modified : 2019-10-04 12:04
*   Describe      :
*
*******************************************************/

#ifndef  _LAZYPRIM_H
#define  _LAZYPRIM_H

#include <vector>
#include "MinHeap.h"

template <typename Graph, typename Weight>
class LazyPrim {
public:
    LazyPrim(Graph& graph) :
        graph(graph),
        pq(MinHeap<Edge<Weight>>(graph.E())),
        marked(std::vector<bool>(graph.V(), false)),
        mstWeight(0) {
        mst.clear();

        // Lazy Prim
        // 时间复杂度O(ElogE)
        visit(0);
        while(!pq.empty()) {
            Edge<Weight> e = pq.extractMin();
            if(marked[e.v()] == marked[e.w()])  // 忽略自环边
                continue;

            mst.push_back(e);
            if(!marked[e.v()]) {
                visit(e.v());
            }
            else {
                visit(e.w());
            }
        }

        for(size_t i = 0; i < mst.size(); ++i) {
            mstWeight += mst[i].wt();
        }
    }
    
    ~LazyPrim() { }

    std::vector<Edge<Weight>> mstEdges() { return mst; }
    Weight result() { return mstWeight; }

private:
    // 遍历节点v所有邻边（剔除已经遍历的节点对应的邻边），添加到最小堆
    void visit(int v) {
        assert(!marked[v]);
        marked[v] = true;

        typename Graph::Iterator iter(graph, v);
        for(Edge<Weight>* p = iter.begin(); !iter.end(); p = iter.next()) {
            if(!marked[p->another(v)]) {
                pq.insert(*p);
            }
        }
    }
    
private:
    Graph& graph;
    MinHeap<Edge<Weight>> pq;
    std::vector<bool> marked;     
    std::vector<Edge<Weight>> mst; // 存放MST
    Weight mstWeight;              // 存放MST总权重
};

#endif // _LAZYPRIM_H

