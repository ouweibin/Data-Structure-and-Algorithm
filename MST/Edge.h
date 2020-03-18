
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : Edge.h
*   Last Modified : 2019-10-01 16:40
*   Describe      :
*
*******************************************************/

#ifndef  _EDGE_H
#define  _EDGE_H

#include <iostream>
#include <cassert>

template <typename Weight>
class Edge {
public:
    Edge(int a, int b, Weight w) :
        a(a), b(b), weight(w) { }
    Edge() { }
    ~Edge() { }

    int v() { return a; }
    int w() { return b; }
    Weight wt() {return weight; }

    int another(int x) {
        assert(x == a || x == b);
        return x == a ? b : a;
    }

    friend std::ostream& operator<<(std::ostream& os, const Edge& e) {
        os << e.a << "-" << e.b << ": " << e.weight;
        return os;
    }

    bool operator<(Edge<Weight>& e) { return weight < e.wt(); }
    bool operator<=(Edge<Weight>& e) { return weight <= e.wt(); }
    bool operator>(Edge<Weight>& e) { return weight > e.wt(); }
    bool operator>=(Edge<Weight>& e) { return weight >= e.wt(); }
    bool operator==(Edge<Weight>& e) { return weight == e.wt(); }

private:
    int a;
    int b;
    Weight weight;
};

#endif // _EDGE_H

