
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_bellmanford.cc
*   Last Modified : 2019-10-11 20:33
*   Describe      :
*
*******************************************************/

#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "BellmanFord.h"

int main() {
    std::string filename = "../testG2.txt";
    int V = 5;
    
    SparseGraph<int> graph(true, V);
    ReadGraph<SparseGraph<int>, int> readGraph(graph, filename);

    std::cout << "Test Bellman-Ford: " << std::endl;
    BellmanFord<SparseGraph<int>, int> bellmanFord(graph, 0);
    for(int i = 1; i < V; ++i) {
        std::cout << "Shortest Path to " << i << " : " << bellmanFord.shortestPathTo(i) << std::endl;
        bellmanFord.showPath(i);
        std::cout << "---------------" << std::endl;
    }

    return 0;
}

