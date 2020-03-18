
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : ShortestPath.h
*   Last Modified : 2019-09-30 16:52
*   Describe      :
*
*******************************************************/

#ifndef  _SHORTESTPATH_H
#define  _SHORTESTPATH_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstddef>

// bfs求解无权图两个节点之间的最短路径
template <typename Graph>
class ShortestPath {
public:
    ShortestPath(Graph& graph, int v) :
        graph(graph) {
        assert(v >= 0 && v < graph.V());
        this->v = v;

        visited = std::vector<bool>(graph.V(), false);
        from = std::vector<int>(graph.V(), -1);
        order = std::vector<int>(graph.V(), -1);

        // bfs
        std::queue<int> q;
        q.push(v);
        visited[v] = true;
        order[v] = 0;
        while(!q.empty()) {
            int tmp = q.front();
            q.pop();

            typename Graph::Iterator iter(graph, tmp);
            for(int i = iter.begin(); !iter.end(); i = iter.next()) {
                if(!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                    from[i] = tmp;
                    order[i] = order[tmp] + 1; // 下一个等于上一个的路径长度加一
                }
            }
        }
    }

    ~ShortestPath() { }

    bool hasPath(int w) {
        assert(w >= 0 && w < graph.V());
        return visited[w];
    }

    void path(int w, std::vector<int>& record) {
        assert(w >= 0 && w < graph.V());
        std::stack<int> s;

        int tmp = w;
        while(tmp != -1) {
            s.push(tmp);
            tmp = from[tmp];
        }

        record.clear();
        while(!s.empty()) {
            record.push_back(s.top());
            s.pop();
        }
    }

    void showPath(int w) {
        assert(w >= 0 && w < graph.V());

        std::vector<int> record;
        path(w, record);
        
        for(size_t i = 0; i < record.size(); ++i) {
            std::cout << record[i];
            if(i+1 == record.size()) {
                std::cout << std::endl;
            }
            else {
                std::cout << " -> ";
            }
        }
    }

    int length(int w) {
        assert(w >= 0 && w < graph.V());
        return order[w];
    }

private:
    Graph& graph;
    int v;
    std::vector<bool> visited;
    std::vector<int> from;
    std::vector<int> order;
};

#endif // _SHORTESTPATH_H

