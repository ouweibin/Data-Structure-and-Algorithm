
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_heapsort1.cc
*   Last Modified : 2019-10-02 12:20
*   Describe      :
*
*******************************************************/

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "MaxHeap.h"

template <typename T>
bool isSorted(T arr[], int n) {
    for(int i = 0; i < n-1; ++i) {
        if(arr[i] > arr[i+1])
            return false;
    }
    return true;
}

template <typename T>
void heapSort1(T arr[], int n) {
    MaxHeap<T> maxheap(n);
    // O(nlogn)
    for(int i = 0; i < n; ++i) {
        maxheap.insert(arr[i]);
    }

    for(int i = n-1; i >= 0; --i) {
        arr[i] = maxheap.extractMax();
    }
}

template <typename T>
void heapSort2(T arr[], int n) {
    // O(n)
    MaxHeap<T> maxheap(arr, n);

    for(int i = n-1; i >= 0; --i) {
        arr[i] = maxheap.extractMax();
    }
}

int main() {
    int n = 1000000;

    srand(static_cast<unsigned int>(time(NULL)));
    
    int* arr1 = new int[n];
    int* arr2 = new int[n];

    for(int i = 0; i < n; ++i) {
        arr1[i] = rand()%n;
    }
    std::copy(arr1, arr1+n, arr2);

    clock_t start = clock();
    heapSort1(arr1, n);
    clock_t end = clock();
    assert(isSorted(arr1, n));
    std::cout << "heapSort1: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;

    start = clock();
    heapSort2(arr2, n);
    end = clock();
    assert(isSorted(arr2, n));
    std::cout << "heapSort2: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;

    return 0;
}
