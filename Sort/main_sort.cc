
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_sort.cc
*   Last Modified : 2019-10-11 10:22
*   Describe      :
*
*******************************************************/

#include <vector>

#include "TestHelper.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

#define LEVEL 10000

int main() {
    std::vector<int> testData1 = generateRandomVector(LEVEL, 0, 1000);
    std::vector<int> testData2 = generateNearlyOrderVector(LEVEL, 100);

    sortTest("BubbleSort(RandomVector)", BubbleSort, testData1);
    sortTest("BubbleSort(NearlyOrderVector)", BubbleSort, testData2);

    sortTest("MergeSort(RandomVector)", MergeSort, testData1);
    sortTest("MergeSort(NearlyOrderVector)", MergeSort, testData2);

    sortTest("QuickSort(RandomVector)", QuickSort, testData1);
    sortTest("QuickSort(NearlyOrderVector)", QuickSort, testData2);

    return 0;
}


