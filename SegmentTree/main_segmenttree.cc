
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_segmenttree.cc
*   Last Modified : 2019-10-14 17:16
*   Describe      :
*
*******************************************************/

#include <iostream>
#include "SegmentTree.h"

int main() {
    int nums[] = { -2, 0, 3, -5, 2, -1 };
    SegmentTree<int> segmentTree(nums, sizeof(nums)/sizeof(int), [](int a, int b)->int {
                return a + b; });

    std::cout << segmentTree.query(2, 5) << std::endl;

    segmentTree.set(3, 5);
    std::cout << segmentTree.query(2, 5) << std::endl;

    segmentTree.print();
    return 0;
}

