
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_dijkstra.cc
*   Last Modified : 2019-10-11 20:33
*   Describe      :
*
*******************************************************/

#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Dijkstra.h"

int main() {
    std::string filename = "../testG1.txt";
    int V = 5;
    
    SparseGraph<int> graph(true, V);
    ReadGraph<SparseGraph<int>, int> readGraph(graph, filename);

    std::cout << "Test Dijkstra: " << std::endl;
    Dijkstra<SparseGraph<int>, int> dijk(graph, 0);
    for(int i = 1; i < V; ++i) {
        std::cout << "Shortest Path to " << i << " : " << dijk.shortestPathTo(i) << std::endl;
        dijk.showPath(i);
        std::cout << "---------------" << std::endl;
    }

    return 0;
}

