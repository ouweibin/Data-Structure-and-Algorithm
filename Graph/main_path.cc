
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_path.cc
*   Last Modified : 2019-09-30 20:17
*   Describe      :
*
*******************************************************/

#include <iostream>

#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "Path.h"
#include "ShortestPath.h"

int main() {
    std::string filename = "../testG2.txt";
    SparseGraph graph(false, 7);
    ReadGraph<SparseGraph> ReadGraph(graph, filename);
    graph.show();
    std::cout << std::endl;

    Path<SparseGraph> dfs(graph, 0);
    std::cout << "DFS: ";
    dfs.showPath(4);

    ShortestPath<SparseGraph> bfs(graph, 0);
    std::cout << "BFS: ";
    bfs.showPath(4);
    std::cout << "The length of ShortestPath is " << bfs.length(4) << std::endl;

    return 0;
}

