
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : MinHeap.h
*   Last Modified : 2019-10-01 17:04
*   Describe      :
*
*******************************************************/

#ifndef  _MINHEAP_H
#define  _MINHEAP_H

#include <iostream>
#include <algorithm>
#include <cassert>

// 最小堆实现
template <typename T>
class MinHeap {
public:
    MinHeap(int capacity) {
        data =  new T[capacity+1];
        this->capacity = capacity;
        count = 0;
    }

    MinHeap(T arr[], int n) {
        data = new T[n+1];
        capacity = n;

        for(int i = 0; i < n; ++i) {
            data[i+1] = arr[i];
        }
        count = n;

        for(int i = count/2; i >=1; --i) {
            shiftDown(i);
        }
    }

    ~MinHeap() { delete[] data; }

    int size() { return count; }
    bool empty() { return count == 0; }

    void insert(T t) {
        assert(count+1 <= capacity);
        data[count+1] = t;
        shiftUp(count+1);
        count++;
    }

    T extractMin() {
        assert(count > 0);
        T ret = data[1];
        std::swap(data[1], data[count]);
        count--;
        shiftDown(1);
        return ret;
    }

    T getMin() {
        assert(count > 0);
        return data[1];
    }

    void show() {
        std::cout << "| ";
        for(int i = 1; i <= count; ++i) {
            std::cout << data[i].wt() << "| ";
            std::cout << std::endl;
        }
    }

private:
    void shiftUp(int k) {
        while(k > 1 && data[k/2] > data[k]) {
            std::swap(data[k/2], data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while(2*k <= count) {
            int j = 2*k;
            if(j+1 <= count && data[j+1] < data[j]) j++;
            if(data[k] <= data[j])
                break;
            std::swap(data[k], data[j]);
            k = j;
        }
    } 

private:
    T* data;
    int count;
    int capacity;
};

#endif // _MINHEAP_H

