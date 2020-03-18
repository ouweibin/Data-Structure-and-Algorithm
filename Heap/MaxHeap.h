
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : MaxHeap.h
*   Last Modified : 2019-10-02 12:16
*   Describe      :
*
*******************************************************/

#ifndef  _MAXHEAP_H
#define  _MAXHEAP_H

#include <algorithm>
#include <cassert>

template <typename Item>
class MaxHeap {
public:
    MaxHeap(int capacity) {
        data = new Item[capacity+1];  // data[0]不使用
        this->capacity = capacity;
        count = 0;
    }

    // heapify
    MaxHeap(Item arr[], int n) {
        data = new Item[n+1];
        capacity = n;
        for(int i = 0; i < n; ++i) {
            data[i+1] = arr[i];
        }
        count = n;
        for(int i = count/2; i >=1; --i) {
            shiftDown(i);
        }
    }

    ~MaxHeap() {
        delete[] data;
    }

    int size() { return count; }
    bool empty() { return count == 0; }

    Item extractMax() {
        assert(count > 0);
        Item ret = data[1];

        std::swap(data[1], data[count]);
        count--;
        shiftDown(1);
        return ret;
    }

    Item getMax() {
        assert(count > 0);
        return data[1];
    }

    void insert(Item item) {
        assert(count+1 <= capacity);
        data[count+1] = item;
        count++;
        shiftUp(count);
    }

private:
    // 调整堆中索引为k的元素将这个元素向上调整到合适的位置
    void shiftUp(int k) {
        while(k > 1 && data[k/2] < data[k]) {
            std::swap(data[k/2], data[k]);
            k /= 2;
        }
    }
    
    // 调整堆中索引为k的元素将这个元素向下调整到合适的位置
    void shiftDown(int k) {
        while(2*k <= count) {
            int j = 2*k;
            if(j+1 <= count && data[j+1] > data[j]) {
                j++;
            }
            if(data[k] >= data[j]) {
                break;
            }
            std::swap(data[k], data[j]);
            k = j;
        }
    }

private:
    Item* data;
    int capacity;
    int count;
};

#endif // _MAXHEAP_H

