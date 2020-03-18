
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : HeapSort.h
*   Last Modified : 2019-10-02 11:13
*   Describe      :
*
*******************************************************/

#ifndef  _HEAPSORT_H
#define  _HEAPSORT_H

#include <algorithm>

template <typename T>
void shiftDown(T arr[], int n, int k) {
    while(2*k+1 < n) {
        int j = 2*k+1;
        if(j+1 < n && arr[j+1] > arr[j]) {
            j++;
        }
        if(arr[k] >= arr[j]) {
            break;
        }
        std::swap(arr[k], arr[j]);
        k = j;
    }
}

template <typename T>
void heapSort(T arr[], int n) {
    for(int i = (n-1)/2; i >= 0; --i) {
        shiftDown(arr, n, i);
    }

    for(int i = n-1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        shiftDown(arr, i, 0);
    }
}

#endif // _HEAPSORT_H

