
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : BellmanFord.h
*   Last Modified : 2019-10-11 20:29
*   Describe      :
*
*******************************************************/

#ifndef  _BELLMANFORD_H
#define  _BELLMANFORD_H

#include <iostream>
#include <vector>
#include <stack>
#include "Edge.h"

template <typename Graph, typename Weight>
class BellmanFord {
public:
    BellmanFord(Graph& graph, int s) :
        graph(graph),
        s(s),
        distTo(graph.V()),
        from(graph.V(), nullptr),
        hasNegativeCycle(false) {
        // Bellman-Ford
        for(int pass = 1; pass < graph.V(); ++pass) { // V-1轮
            for(int i = 0; i < graph.V(); ++i) {
                typename Graph::Iterator iter(graph, i);
                for(auto p = iter.begin(); !iter.end(); p = iter.next()) {
                    if(from[p->w()] == nullptr || distTo[p->v()] + p->wt() < distTo[p->w()]) {
                        distTo[p->w()] = distTo[p->v()] + p->wt();
                        from[p->w()] = p;
                    }
                }
            }            
        }
        hasNegativeCycle = detectNegativeCycle();
    }

    ~BellmanFord() { }

    bool negativeCycle() {
        return hasNegativeCycle;
    }

    Weight shortestPathTo(int w) {
        assert(w >=0 && w < graph.V());
        assert(!hasNegativeCycle);
        return distTo[w];
    }

    bool hasPathTo(int w) {
        assert(w >= 0 && w < graph.V());
        return from[w] != nullptr;
    }

    void shortestPath(int w, std::vector<Edge<Weight>>& record) {
        assert(w >= 0 && w < graph.V());
        assert(!hasNegativeCycle);

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
        assert(!hasNegativeCycle);

        std::vector<Edge<Weight>> record;
        shortestPath(w, record);
        
        for(size_t i = 0; i < record.size(); ++i) {
            std::cout << record[i].v() << " -> ";
            if(i == record.size()-1)
                std::cout << record[i].w() << std::endl;
        }
    }

private:
    bool detectNegativeCycle() {
        for(int i = 0; i < graph.V(); ++i) {
            typename Graph::Iterator iter(graph, i);
            for(auto p = iter.begin(); !iter.end(); p = iter.next()) {
                if(from[p->w()] == nullptr || distTo[p->v()] + p->wt() < distTo[p->w()])
                    return true;
            }
        }
        return false;
    }

private:
    Graph& graph;
    int s;
    std::vector<Weight> distTo;
    std::vector<Edge<Weight>*> from;
    bool hasNegativeCycle;
};

#endif // _BELLMANFORD_H

