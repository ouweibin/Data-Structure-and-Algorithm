
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : ReadGraph.h
*   Last Modified : 2019-09-30 22:06
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

template <typename Graph, typename Weight>
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

            int a, b;
            Weight w;
            ss >> a >> b >> w;
            assert(a >= 0 && a < vertexes);
            assert(b >= 0 && b < vertexes);
            graph.addEdge(a, b, w);
        }
    }
};

#endif // _READGRAPH_H

