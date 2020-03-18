
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_component.cc
*   Last Modified : 2019-09-30 20:14
*   Describe      :
*
*******************************************************/

#include <iostream>

#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "Component.h"

int main() {
    std::string filename1 = "../testG1.txt";
    SparseGraph graph1(false, 13);
    ReadGraph<SparseGraph> ReadGraph1(graph1, filename1);
    Component<SparseGraph> component1(graph1);
    std::cout << "TestG1.txt, Component count " << component1.count() << std::endl;

    std::string filename2 = "../testG2.txt";
    SparseGraph graph2(false, 7);
    ReadGraph<SparseGraph> ReadGraph2(graph2, filename2);
    Component<SparseGraph> component2(graph2);
    std::cout << "TestG2.txt, Component count " << component2.count() << std::endl;

    return 0;
}

