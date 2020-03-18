
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : Component.h
*   Last Modified : 2019-09-30 15:30
*   Describe      : 
*
*******************************************************/

#ifndef  _COMPONENT_H
#define  _COMPONENT_H

#include <vector>

// DFS求解连通分量
template <typename Graph>
class Component {
public:
    Component(Graph& graph) :
        graph(graph),
        ccount(0) {
        visited = std::vector<bool>(graph.V(), false);
        id = std::vector<int>(graph.V(), -1);

        for(int i = 0; i < graph.V(); ++i) {
            if(!visited[i]) {
                dfs(i);
                ccount++;
            }
        }
    }

    ~Component() { }

    int count() { return ccount; }

    bool isConnected(int v, int w) {
        assert(v >= 0 && v < graph.V());
        assert(w >= 0 && v < graph.V());
        return id[v] == id[w];
    }

private:
    void dfs(int v) {
        visited[v] = true;
        id[v] = ccount;
        typename Graph::Iterator iter(graph, v);
        for(int i = iter.begin(); !iter.end(); i = iter.next()) {
            if(!visited[i]) {
                dfs(i);
            }
        }
    }

private:
    Graph& graph;
    int ccount;              // 连通分量个数
    std::vector<bool> visited;
    std::vector<int> id;     // 连通的节点id相同
};

#endif // _COMPONENT_H

