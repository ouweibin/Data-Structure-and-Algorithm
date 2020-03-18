
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_indexmaxheap.cc
*   Last Modified : 2019-10-02 20:40
*   Describe      :
*
*******************************************************/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include "IndexMaxHeap.h"

template <typename T>
bool isSorted(T arr[], int n) {
    for(int i = 0; i < n-1; ++i) {
        if(arr[i] > arr[i+1])
            return false;
    }
    return true;
}

template <typename T>
void heapSortUsingIndexMaxHeap(T arr[], int n) {
    IndexMaxHeap<T> indexMaxHeap(n);
    
    for(int i = 0; i < n; ++i) {
        indexMaxHeap.insert(i, arr[i]);
    }

    for(int i = n-1; i >= 0; --i) {
        arr[i] = indexMaxHeap.extractMax();
    }

}

int main() {
    int n = 1000000;

    srand(static_cast<unsigned int>(time(NULL)));
    
    int* arr = new int[n];
    for(int i = 0; i < n; ++i) {
        arr[i] = rand()%n;
    }

    clock_t start = clock();
    heapSortUsingIndexMaxHeap(arr, n);
    clock_t end = clock();
    assert(isSorted(arr, n));
    std::cout << "heapSortUsingIndexMaxHeap: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;

    return 0;
}
