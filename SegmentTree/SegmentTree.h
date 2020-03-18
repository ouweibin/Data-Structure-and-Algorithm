
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : SegmentTree.h
*   Last Modified : 2019-10-14 17:12
*   Describe      :
*
*******************************************************/

#ifndef  _SEGMENTTREE_H
#define  _SEGMENTTREE_H

#include <iostream>
#include <functional>
#include <cassert>
#include <climits>

template <typename T>
class SegmentTree {
public:
    SegmentTree(T arr[], int n, std::function<T(T, T)> func) :
        merge(func),
        count(n) {
        data = new T[n];
        for(int i = 0; i < n; ++i) {
            data[i] = arr[i];
        }

        tree = new T[4*n];       // 保证足够容量
        for(int i = 0; i < 4*n; ++i) {
            tree[i] = INT_MIN;   // 数据不包含INT_MIN
        }

        buildSegmentTree(0, 0, count-1);
    }

    T query(int queryL, int queryR) {
        assert(queryL >= 0 && queryL < count && queryR >= 0 && queryR < count && queryL <= queryR);
        return query(0, 0, count-1, queryL, queryR);
    }

    void set(int index, T e) {
        assert(index >= 0 && index < count);
        data[index] = e;
        set(0, 0, count-1, index, e);
    }

    int size() { return count; }
    
    T get(int index) {
        assert(index >= 0 && index < count);
        return data[index];
    }

    void print() {
        std::cout << "[";
        for(int i = 0; i < 4*count; ++i) {
            if(tree[i] != INT_MIN) {
                std::cout << tree[i];
            }
            else {
                std::cout << "null";
            }

            if(i != 4*count-1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" <<std::endl;
    }

private:
    void buildSegmentTree(int treeIndex, int left, int right) {
        if(left == right) {
            tree[treeIndex] = data[left];
            return;
        }

        int leftTreeIndex = leftChild(treeIndex);
        int rightTreeIndex = rightChild(treeIndex);
        int middle = left + (right - left) / 2;

        buildSegmentTree(leftTreeIndex, left, middle);
        buildSegmentTree(rightTreeIndex, middle+1, right);

        tree[treeIndex] = merge(tree[leftTreeIndex], tree[rightTreeIndex]);
    }

    T query(int treeIndex, int left, int right, int queryL, int queryR) {
        if(left == queryL && right == queryR) {
            return tree[treeIndex];
        }

        int middle = left + (right - left) / 2;
        int leftTreeIndex = leftChild(treeIndex);
        int rightTreeIndex =rightChild(treeIndex);

        if(queryL >= middle+1) {
            return query(rightTreeIndex, middle+1, right, queryL, queryR);
        }
        else if(queryR <= middle) {
            return query(leftTreeIndex, left, middle, queryL, queryR);
        }
        else {
            T leftResult = query(leftTreeIndex, left, middle, queryL, middle);
            T rightResult = query(rightTreeIndex, middle+1, right, middle+1, queryR);
            return merge(leftResult, rightResult);
        }
    }

    void set(int treeIndex, int left, int right, int index, int e) {
        if(left == right) {
            tree[treeIndex] = e;
            return;
        }

        int middle = left + (right - left) / 2;
        int leftTreeIndex = leftChild(treeIndex);
        int rightTreeIndex = rightChild(treeIndex);

        if(index >= middle+1) {
            set(rightTreeIndex, middle+1, right, index, e);
        }
        else {
            set(leftTreeIndex, left, middle, index, e);
        }

        tree[treeIndex] = merge(tree[leftTreeIndex], tree[rightTreeIndex]);
    }

    int leftChild(int index) {
        return 2*index + 1;
    }
    
    int rightChild(int index) {
        return 2*index + 2;
    }

private:
    std::function<T(T, T)> merge;
    T* data;   // 备份数据
    T* tree;   // 线段树
    int count;
};

#endif // _SEGMENTTREE_H


