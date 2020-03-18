
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main.cc
*   Last Modified : 2019-10-02 07:51
*   Describe      :
*
*******************************************************/

#include <iostream>

#include "MaxHeap.h"

int main() {
    MaxHeap<int> maxheap = MaxHeap<int>(100);

    srand(static_cast<unsigned int>(time(nullptr)));
    for(int i = 0; i < 63; ++i) {
        maxheap.insert(rand()%100);
    }

    while(!maxheap.empty()) {
        std::cout << maxheap.extractMax() << " ";
    }
    std::cout << std::endl;

    return 0;
}


