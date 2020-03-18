
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : UnionFind.h
*   Last Modified : 2019-10-04 12:34
*   Describe      :
*
*******************************************************/

#ifndef  _UNIONFIND_H
#define  _UNIONFIND_H

#include <cassert>

class UnionFind {
public:
    UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
        count = n;
    }

    ~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

    int size() { return count; }

    bool isConnected(int v, int w) {
        return find(v) == find(w);
    }

    int find(int v) {
        assert(v >= 0 && v < count);
        while(v != parent[v]) {
            parent[v] = parent[parent[v]];
            v = parent[v];
        }
        return v;
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

#endif // _UNIONFIND_H

