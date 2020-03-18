
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : IndexMaxHeap.h
*   Last Modified : 2019-10-02 20:40
*   Describe      :
*
*******************************************************/

#ifndef  _INDEXMAXHEAP_H
#define  _INDEXMAXHEAP_H

#include <iostream>
#include <algorithm>
#include <cassert>

template <typename Item>
class IndexMaxHeap {
public:
    IndexMaxHeap(int capacity) {
        data = new Item[capacity+1];  // data[0]不使用
        indexes= new int[capacity+1];
        reverse = new int[capacity+1];
        for(int i = 0; i <= capacity; ++i) {
            reverse[i] = 0;           // indexes[0]不使用
        }
        
        this->capacity = capacity;
        count = 0;
    }

    ~IndexMaxHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    int size() { return count; }
    bool empty() { return count == 0; }

    Item extractMax() {
        assert(count > 0);
        Item ret = data[indexes[1]];

        std::swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        shiftDown(1);
        return ret;
    }

    int extractMaxIndex() {
        assert(count > 0);

        int ret = indexes[1]-1;  // 真正索引
        std::swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;

        shiftDown(1);
        return ret;
    }

    Item getMax() {
        assert(count > 0);
        return data[indexes[1]];
    }

    int getMaxIndex() {
        assert(count > 0);
        return indexes[1]-1;
    }

    bool contain(int i) {
        assert(i+1 >= 1 && i+1 <= capacity);
        return reverse[i+1] != 0;
    }

    Item getItem(int i) {
        assert(contain(i));
        return data[i+1];
    }

    void insert(int i, Item item) {
        assert(count+1 <= capacity);
        assert(i+1 >= 1 && i+1 <= capacity);
        
        i += 1;
        data[i] = item;         // 不使用data[0]
        indexes[count+1] = i;   // 真正索引+1
        reverse[i] = count+1;
        count++;

        shiftUp(count);
    }

    void change(int i, Item newItem) {
        assert(contain(i));
        i += 1;
        data[i] = newItem;

        // 找出indexes[j] == i
        // for(int j = 0; j <= count; ++j) {  // O(n)
        //    if(indexes[j] == i) {
        //        shiftUp(j);
        //        shiftDown(j);
        //        return;
        //    }
        // }

        int j = reverse[i];   // O(1)
        shiftUp(j);
        shiftDown(j);
    }

private:
    // 调整堆中索引为k的元素将这个元素向上调整到合适的位置
    void shiftUp(int k) {
        while(k > 1 && data[indexes[k/2]] < data[indexes[k]]) {
            std::swap(indexes[k/2], indexes[k]);
            reverse[indexes[k/2]] = k/2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }
    
    // 调整堆中索引为k的元素将这个元素向下调整到合适的位置
    void shiftDown(int k) {
        while(2*k <= count) {
            int j = 2*k;
            if(j+1 <= count && data[indexes[j+1]] > data[indexes[j]]) {
                j += 1;
            }
            if(data[indexes[k]] >= data[indexes[j]]) {
                break;
            }
            std::swap(indexes[k], indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

private:
    Item* data;
    int* indexes;  // 存放索引，实际索引+1
    int* reverse;  // 表示实际索引在indexes中的位置
    int capacity;
    int count;
};

#endif // _INDEXMAXHEAP_H

