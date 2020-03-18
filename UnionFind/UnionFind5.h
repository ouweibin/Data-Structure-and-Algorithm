
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : UnionFind5.h
*   Last Modified : 2019-10-04 09:56
*   Describe      :
*
*******************************************************/

#ifndef  _UNIONFIND5_H
#define  _UNIONFIND5_H

#include <cassert>

namespace UF5 {

class UnionFind {
public:
    UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; ++i) {
            parent[i] = i;   // 初始化指向自己
            rank[i] = 1;
        }
        count = n;
    }

    ~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

    int find(int v) {
        assert(v >= 0 && v < count);
        // path compression 1
        while(v != parent[v]) {
            parent[v] = parent[parent[v]];
            v = parent[v];
        }
        return v;

        // path compression 2
        // if(v != parent[v]) {
        //     parent[v] = find(parent[v]);
        // }
        // return parent[v];
    }

    bool isConnected(int v, int w) {
        return find(v) == find(w);
    }

    void unionElements(int v, int w) {
        int vRoot = find(v);
        int wRoot = find(w);
        if(vRoot == wRoot)
            return;
        
        if(rank[vRoot] < rank[wRoot]) {
            parent[vRoot] = wRoot;
        }
        else if(rank[vRoot] > rank[wRoot]) {
            parent[wRoot] = vRoot;
        }
        else {
            parent[vRoot] = wRoot;
            rank[wRoot] += 1;
        }
    }

private:
    int* parent;
    int* rank;
    int count;
};

}

#endif // _UNIONFIND5_H

