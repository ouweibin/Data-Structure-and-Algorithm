
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : UnionFind2.h
*   Last Modified : 2019-10-03 22:35
*   Describe      :
*
*******************************************************/

#ifndef  _UNIONFIND2_H
#define  _UNIONFIND2_H

#include <cassert>

namespace UF2 {

class UnionFind {
public:
    UnionFind(int n) {
        parent = new int[n];
        for(int i = 0; i < n; ++i) {
            parent[i] = i;   // 初始化指向自己
        }
        count = n;
    }

    ~UnionFind() {
        delete[] parent;
    }

    int find(int v) {
        assert(v >= 0 && v < count);
        while(v != parent[v]) {
            v = parent[v];
        }
        return v;
    }

    bool isConnected(int v, int w) {
        return find(v) == find(w);
    }

    void unionElements(int v, int w) {
        int vRoot = find(v);
        int wRoot = find(w);
        if(vRoot == wRoot)
            return;
        parent[vRoot] = wRoot;
    }

private:
    int* parent;
    int count;
};

}

#endif // _UNIONFIND2_H

