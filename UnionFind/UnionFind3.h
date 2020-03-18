
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : UnionFind3.h
*   Last Modified : 2019-10-04 07:47
*   Describe      :
*
*******************************************************/

#ifndef  _UNIONFIND3_H
#define  _UNIONFIND3_H

#include <cassert>

namespace UF3 {

class UnionFind {
public:
    UnionFind(int n) {
        parent = new int[n];
        sz = new int[n];
        for(int i = 0; i < n; ++i) {
            parent[i] = i;   // 初始化指向自己
            sz[i] = 1;
        }
        count = n;
    }

    ~UnionFind() {
        delete[] parent;
        delete[] sz;
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
        
        if(sz[vRoot] < sz[wRoot]) {
            parent[vRoot] = wRoot;
            sz[wRoot] += sz[vRoot];
        }
        else {
            parent[wRoot] = vRoot;
            sz[vRoot] += sz[wRoot];
        }
    }

private:
    int* parent;
    int* sz;
    int count;
};

}

#endif // _UNIONFIND3_H

