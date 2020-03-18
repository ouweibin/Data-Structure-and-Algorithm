
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_heapsort2.cc
*   Last Modified : 2019-10-02 12:17
*   Describe      :
*
*******************************************************/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include "HeapSort.h"

template <typename T>
bool isSorted(T arr[], int n) {
    for(int i = 0; i < n-1; ++i) {
        if(arr[i] > arr[i+1])
            return false;
    }
    return true;
}

int main() {
    int n = 1000000;

    srand(static_cast<unsigned int>(time(NULL)));
    
    int* arr = new int[n];
    for(int i = 0; i < n; ++i) {
        arr[i] = rand()%n;
    }

    clock_t start = clock();
    heapSort(arr, n);
    clock_t end = clock();
    assert(isSorted(arr, n));
    std::cout << "heapSort: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;

    return 0;
}
