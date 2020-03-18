
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : Path.h
*   Last Modified : 2019-09-30 16:18
*   Describe      : 
*
*******************************************************/

#ifndef  _PATH_H
#define  _PATH_H

#include <iostream>
#include <vector>
#include <stack>

// 获取v到w的一条路径
template <typename Graph>
class Path {
public:
    Path(Graph& graph, int v) :
        graph(graph) {
        assert(v >= 0 && v < graph.V());
        this->v = v;

        visited = std::vector<bool>(graph.V(), false);
        from = std::vector<int>(graph.V(), -1);

        dfs(v);
    }

    ~Path() { }

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

private:
    void dfs(int v) {
        visited[v] = true;
        typename Graph::Iterator iter(graph, v);
        for(int i = iter.begin(); !iter.end(); i = iter.next()) {
            if(!visited[i]) {
                from[i] = v;
                dfs(i);
            }
        }
    }

private:
    Graph& graph;
    int v;                   // 路径起点
    std::vector<bool> visited;
    std::vector<int> from;   // from[i] = j 表示有j->i这条路径
};

#endif // _PATH_H

