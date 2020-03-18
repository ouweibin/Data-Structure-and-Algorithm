
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : UnionFind1.h
*   Last Modified : 2019-10-03 22:11
*   Describe      :
*
*******************************************************/

#ifndef  _UNIONFIND1_H
#define  _UNIONFIND1_H

#include <cassert>

namespace UF1 {

class UnionFind {
public:
    UnionFind(int n) {
        id = new int[n];
        for(int i = 0; i < n; ++i) {
            id[i] = i;   // 初始化id，保证不重复
        }
        count = n;
    }

    ~UnionFind() {
        delete[] id;
    }

    int find(int v) {
        assert(v >= 0 && v < count);
        return id[v];
    }

    bool isConnected(int v, int w) {
        return find(v) == find(w);
    }

    void unionElements(int v, int w) {
        int vId = find(v);
        int wId = find(w);
        if(vId == wId)
            return;

        for(int i = 0; i < count; ++i) {
            if(id[i] == vId) {
                id[i] = wId;
            }
        }
    }

private:
    int* id;
    int count;
};

}

#endif // _UNIONFIND1_H

