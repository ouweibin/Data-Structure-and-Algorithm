
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_mst.cc
*   Last Modified : 2019-10-04 12:20
*   Describe      :
*
*******************************************************/

#include <iostream>
#include <iomanip>

#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "LazyPrim.h"
#include "Prim.h"
#include "Kruskal.h"

int main() {
    clock_t start, end;
    std::string filename = "../testG1.txt";

    SparseGraph<double> graph(false, 10000);
    ReadGraph<SparseGraph<double>, double> readGraph(graph, filename);
    
    std::cout << "Test Lazy Prim MST: " << std::endl;
    start = clock();
    LazyPrim<SparseGraph<double>, double> lazyPrim(graph);
    end = clock();
    
//    std::vector<Edge<double>> mst = lazyPrim.mstEdges();
//    for(size_t i = 0; i < mst.size(); ++i) {
//        std::cout << "    " << mst[i] << std::endl;
//    }
    std::cout << "The MST weight is " << lazyPrim.result() << std::endl;
    std::cout << "Lazy Prim cost " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;
    std::cout << std::endl;

    std::cout << "Test Prim MST: " << std::endl;
    start = clock();
    Prim<SparseGraph<double>, double> prim(graph);
    end = clock();

//    mst = prim.mstEdges();
//    for(size_t i = 0; i < mst.size(); ++i) {
//        std::cout << "    " << mst[i] << std::endl;
//    }
    std::cout << "The MST weight is " << prim.result() << std::endl;
    std::cout << "Prim cost " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;
    std::cout << std::endl;

    std::cout << "Test Kruskal MST: " << std::endl;
    start = clock();
    Kruskal<SparseGraph<double>, double> kruskal(graph);
    end = clock();

//    mst = kruskal.mstEdges();
//    for(size_t i = 0; i < mst.size(); ++i) {
//        std::cout << "    " << mst[i] << std::endl;
//    }
    std::cout << "The MST weight is " << kruskal.result() << std::endl;
    std::cout << "Kruskal cost " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;
 
    return 0;
}

