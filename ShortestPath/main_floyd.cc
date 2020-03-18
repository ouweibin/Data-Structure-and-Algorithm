
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_floyd.cc
*   Last Modified : 2019-10-12 11:03
*   Describe      :
*
*******************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cassert>
#include <climits>

void ReadAndGenGraph(const std::string& filename, std::vector<std::vector<int>>& matrix) {
    matrix.clear();
    std::ifstream file(filename);
    std::string line;
    int vertexes, edges;

    assert(file.is_open());
    assert(getline(file, line));
    std::stringstream ss(line);
    ss >> vertexes >> edges;

    matrix = std::vector<std::vector<int>>(vertexes, std::vector<int>(vertexes, INT_MAX));
    for(int i = 0; i < vertexes; ++i) {
        matrix[i][i] = 0;
    }

    for(int i = 0; i < edges; ++i) {
        assert(getline(file, line));
        std::stringstream ss(line);
       
        int a, b, w;
        ss >> a >> b >> w;
        assert(a >= 0 && a < vertexes);
        assert(b >= 0 && b < vertexes);
        matrix[a][b] = w;
        matrix[b][a] = w;
    }
}

// record用来记录路径
void Floyd(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& record) {
    assert(matrix.size() == matrix[0].size());
    int n = matrix.size();

    record.clear();
    record = std::vector<std::vector<int>>(n, std::vector<int>(n, -1));

    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                 if(matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX && matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    record[i][j] = k;
                }
            }
        }
    }
}



void ShortestPath(std::vector<std::vector<int>>& matrix, int v, int w) {
    assert(v >= 0 && (size_t)w < matrix.size());
    assert(w >= 0 && (size_t)w < matrix.size());

    if(matrix[v][w] == INT_MAX) {
        std::cout << v << "can't reach " << w << std::endl;
    }
    else {
        std::cout << "Shortest Path from " << v << " to " << w << " : " << matrix[v][w] << std::endl;
    }
}

void getPath(std::vector<int>& path, std::vector<std::vector<int>>& record, int v, int w) {
    if(record[v][w] != -1) {
        int k = record[v][w];
        getPath(path, record, v, k);
        path.push_back(k);
        getPath(path, record, k ,w);
    }
}

void ShowPath(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& record, int v, int w) {
    assert(v >= 0 && (size_t)w < matrix.size());
    assert(w >= 0 && (size_t)w < matrix.size());
    assert(matrix[v][w] != INT_MAX);
    
    std::vector<int> path;
    getPath(path, record, v, w);

    std::cout << v << " -> ";
    for(size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i] << " -> ";
    }
    std::cout << w << std::endl;
    std::cout << "---------------" << std::endl;
}


int main() {
    std::string filename = "../testG1.txt";
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> record;

    ReadAndGenGraph(filename, matrix);
    std::cout << "Test Floyd: " << std::endl;
    Floyd(matrix, record);

    for(int i = 0; i < 5; ++i) {
        for(int j = i+1; j < 5; ++j) {
            ShortestPath(matrix, i, j);
            ShowPath(matrix, record, i, j);
        }
    }

    return 0;
}
