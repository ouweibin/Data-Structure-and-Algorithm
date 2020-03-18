
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : RandomGraph.h
*   Last Modified : 2019-09-30 20:13
*   Describe      :
*
*******************************************************/

#ifndef  _RANDOMGRAPH_H
#define  _RANDOMGRAPH_H

#include <cstdlib>
#include <ctime>

template <typename Graph>
class RandomGraph {
public:
    RandomGraph(Graph& graph, int vertexes, int edges) {
        srand(static_cast<unsigned int>(time(nullptr)));
        for(int i = 0; i < edges; ++i) {
            int v = rand() % vertexes;
            int w = rand() % vertexes;
            graph.addEdge(v, w);
        }
    }
};

#endif // _RANDOMGRAPH_H

