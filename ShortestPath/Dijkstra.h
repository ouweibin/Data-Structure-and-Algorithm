
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : Dijkstra.h
*   Last Modified : 2019-10-11 17:12
*   Describe      :
*
*******************************************************/

#ifndef  _DIJKSTRA_H
#define  _DIJKSTRA_H

#include <iostream>
#include <vector>
#include <stack>
#include "Edge.h"
#include "IndexMinHeap.h"

template <typename Graph, typename Weight>
class Dijkstra {
public:
    Dijkstra(Graph& graph, int s) :
        graph(graph),
        s(s),
        distTo(graph.V()),
        marked(graph.V(), false),
        from(graph.V(), nullptr) {

        IndexMinHeap<Weight> ipq(graph.V());
        ipq.insert(s, distTo[s]);
        marked[s] = true;

        while(!ipq.empty()) {
            int v = ipq.extractMinIndex();
            marked[v] = true;

            typename Graph::Iterator iter(graph, v);
            for(auto p = iter.begin(); !iter.end(); p = iter.next()) {
                int w = p->another(v);
                if(!marked[w]) {
                    if(from[w] == nullptr || distTo[v] + p->wt() < distTo[w]) {
                        distTo[w] = distTo[v] + p->wt();
                        from[w] = p;

                        if(ipq.contain(w))
                            ipq.change(w, distTo[w]);
                        else
                            ipq.insert(w, distTo[w]);
                    }
                }
            }
        }
    }

    ~Dijkstra() { }

    Weight shortestPathTo(int w) {
        assert(w >= 0 && w < graph.V());
        return distTo[w];
    }

    bool hasPathTo(int w) {
        assert(w >= 0 && w < graph.V());
        return marked[w];
    }

    void shortestPath(int w, std::vector<Edge<Weight>>& record) {
        assert(w >= 0 && w < graph.V());
        std::stack<Edge<Weight>*> s;
        Edge<Weight>* e = from[w];
        while(e->v() != this->s) {
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);

        while(!s.empty()) {
            e = s.top();
            record.push_back(*e);
            s.pop();
        }
    }

    void showPath(int w) {
        assert(w >= 0 && w < graph.V());
        std::vector<Edge<Weight>> record;
        shortestPath(w, record);

        for(size_t i = 0; i < record.size(); ++i) {
            std::cout << record[i].v() << " -> ";
            if(i == record.size()-1) {
                std::cout << record[i].w() << std::endl;
            }
        }
    }

private:
    Graph& graph;
    int s;                              // 源节点
    std::vector<Weight> distTo;        // 到某个节点的最短路径
    std::vector<bool> marked;           // 是否已经有最短路径
    std::vector<Edge<Weight>*> from;
};

#endif // _DIJKSTRA_H

