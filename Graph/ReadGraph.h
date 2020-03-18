
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : ReadGraph.h
*   Last Modified : 2019-09-30 14:59
*   Describe      :
*
*******************************************************/

#ifndef  _READGRAPH_H
#define  _READGRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>

template <typename Graph>
class ReadGraph {
public:
    ReadGraph(Graph& graph, const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        int vertexes;
        int edges;

        assert(file.is_open());
        assert(getline(file, line));
        std::stringstream ss(line);
        ss >> vertexes >> edges;
        
        assert(vertexes == graph.V());
        
        for(int i = 0; i < edges; ++i) {
            assert(getline(file, line));
            std::stringstream ss(line);

            int v, w;
            ss >> v >> w;
            assert(v >= 0 && v < vertexes);
            assert(w >= 0 && v < vertexes);
            graph.addEdge(v, w);
        }
    }
};

#endif // _READGRAPH_H

