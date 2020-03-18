
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : IndexMinHeap.h
*   Last Modified : 2019-10-03 10:32
*   Describe      :
*
*******************************************************/

#ifndef  _INDEXMINHEAP_H
#define  _INDEXMINHEAP_H

#include <algorithm>
#include <cassert>

template <typename Item>
class IndexMinHeap {
public:
    IndexMinHeap(int capacity) {
        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];

        for(int i = 0; i <= capacity; ++i) {
            reverse[i] = 0;
        }

        this->capacity = capacity;
        count = 0;
    }

    ~IndexMinHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    int size() { return count; }
    bool empty() { return count == 0; }

    void insert(int index, Item item) {
        assert(count+1 <= capacity);
        assert(index+1 >= 1 && index+1 <= capacity);

        index += 1;
        data[index] = item;
        indexes[count+1] = index;
        reverse[index] = count+1;
        count++;
        shiftUp(count);
        
    }

    Item extractMin() {
        assert(count > 0);
        Item ret = data[indexes[1]];
        std::swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        shiftDown(1);
        return ret;
    }

    int extractMinIndex() {
        assert(count > 0);
        int ret = indexes[1] - 1;
        std::swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        shiftDown(1);
        return ret;
    }

    Item getMin() {
        assert(count > 0);
        return data[indexes[1]];
    }

    int getMinIndex() {
        assert(count > 0);
        return indexes[1] - 1;
    }

    bool contain(int i) {
        return reverse[i+1] != 0;
    }

    Item getItem(int i) {
        assert(contain(i));
        return data[i+1];
    }

    void change(int i, Item newItem) {
        assert(contain(i));
        i += 1;
        data[i] = newItem;
        
        shiftUp(reverse[i]);
        shiftDown(reverse[i]);
    }

private:
    void shiftUp(int k) {
        while(k > 1 && data[indexes[k/2]] > data[indexes[k]]) {
            std::swap(indexes[k/2], indexes[k]);
            reverse[indexes[k/2]] = k/2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while(2*k <= count) {
            int j = 2*k;
            if(j+1 <= count && data[indexes[j]] > data[indexes[j+1]]) {
                j += 1;
            }
            if(data[indexes[k]] <= data[indexes[j]])
                break;

            std::swap(indexes[k], indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

private:
    Item* data;
    int* indexes;
    int* reverse;

    int count;
    int capacity;
};


#endif // _INDEXMINHEAP_H


