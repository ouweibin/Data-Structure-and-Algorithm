
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_uf.cc
*   Last Modified : 2019-10-04 09:52
*   Describe      :
*
*******************************************************/

#include <iostream>
#include <cstdlib>

#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"
#include "UnionFind5.h"

void testUF1(int n) {
    srand(static_cast<unsigned int>(time(nullptr)));
    UF1::UnionFind uf(n);

    clock_t start = clock();
    for(int i = 0; i < n; ++i) {
        int v = rand()%n;
        int w = rand()%n;
        uf.unionElements(v, w);
    }
    for(int i = 0; i < n; ++i) {
        int v = rand()%n;
        int w = rand()%n;
        uf.isConnected(v, w);
    }
    clock_t end = clock();

    std::cout << "UF1, " << n << " ops, " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;
}

void testUF2(int n) {
    srand(static_cast<unsigned int>(time(nullptr)));
    UF2::UnionFind uf(n);

    clock_t start = clock();
    for(int i = 0; i < n; ++i) {
        int v = rand()%n;
        int w = rand()%n;
        uf.unionElements(v, w);
    }
    for(int i = 0; i < n; ++i) {
        int v = rand()%n;
        int w = rand()%n;
        uf.isConnected(v, w);
    }
    clock_t end = clock();

    std::cout << "UF2, " << n << " ops, " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;
}

void testUF3(int n) {
    srand(static_cast<unsigned int>(time(nullptr)));
    UF3::UnionFind uf(n);

    clock_t start = clock();
    for(int i = 0; i < n; ++i) {
        int v = rand()%n;
        int w = rand()%n;
        uf.unionElements(v, w);
    }
    for(int i = 0; i < n; ++i) {
        int v = rand()%n;
        int w = rand()%n;
        uf.isConnected(v, w);
    }
    clock_t end = clock();

    std::cout << "UF3, " << n << " ops, " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;
}

void testUF4(int n) {
    srand(static_cast<unsigned int>(time(nullptr)));
    UF4::UnionFind uf(n);

    clock_t start = clock();
    for(int i = 0; i < n; ++i) {
        int v = rand()%n;
        int w = rand()%n;
        uf.unionElements(v, w);
    }
    for(int i = 0; i < n; ++i) {
        int v = rand()%n;
        int w = rand()%n;
        uf.isConnected(v, w);
    }
    clock_t end = clock();

    std::cout << "UF4, " << n << " ops, " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;
}


void testUF5(int n) {
    srand(static_cast<unsigned int>(time(nullptr)));
    UF5::UnionFind uf(n);

    clock_t start = clock();
    for(int i = 0; i < n; ++i) {
        int v = rand()%n;
        int w = rand()%n;
        uf.unionElements(v, w);
    }
    for(int i = 0; i < n; ++i) {
        int v = rand()%n;
        int w = rand()%n;
        uf.isConnected(v, w);
    }
    clock_t end = clock();

    std::cout << "UF5, " << n << " ops, " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;
}


int main() {
    int n = 1000000;
//    testUF1(n);
//    testUF2(n);
    testUF3(n);
    testUF4(n);
    testUF5(n);
    return 0;
}

