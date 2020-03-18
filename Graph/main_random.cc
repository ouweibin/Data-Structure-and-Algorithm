
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   edgesmail         : 2478644416@qq.com
*   File Name     : main_random.cc
*   Last Modified : 2019-09-30 20:12
*   Describe      :
*
*******************************************************/

#include <iostream>
#include <vector>
#include <ctime>

#include "DenseGraph.h"
#include "SparseGraph.h"
#include "RandomGraph.h"

int main() {
    int vertexes = 100;
    int edges = vertexes * vertexes / 10;
    bool directed = false;

    SparseGraph graph1 = SparseGraph(directed, vertexes);
    RandomGraph<SparseGraph>(graph1, vertexes, edges);

    std::cout << "test sparse adjacency: " << std::endl;
    SparseGraph::Iterator iter1(graph1, 0);
    std::cout << "    ";
    for(int i = iter1.begin() ; !iter1.end() ; i = iter1.next()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    DenseGraph graph2 = DenseGraph(directed, vertexes);
    RandomGraph<DenseGraph>(graph2, vertexes, edges);

    std::cout << "test dense adjacency: " << std::endl;
    DenseGraph::Iterator iter2(graph2, 0);
    std::cout << "    ";
    for(int i = iter2.begin() ; !iter2.end() ; i = iter2.next()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

