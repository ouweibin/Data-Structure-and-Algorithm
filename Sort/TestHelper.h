
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : TestHelper.h
*   Last Modified : 2019-10-09 20:21
*   Describe      :
*
*******************************************************/

#ifndef  _TESTHELPER_H
#define  _TESTHELPER_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <functional>

std::vector<int> generateRandomVector(int n, int rangeL, int rangeR) {
    std::vector<int> ret(n);
    srand(time(nullptr));
    for(int i = 0; i < n; ++i) {
        ret[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    }
    return ret;
}

std::vector<int> generateNearlyOrderVector(int n, int swapTimes) {
    std::vector<int> ret(n);
    for(int i = 0; i < n; ++i) {
        ret[i] = i;
    }
    srand(time(nullptr));
    for(int i = 0; i < swapTimes; ++i) {
        int pos1 = rand() % n;
        int pos2 = rand() % n;
        std::swap(ret[pos1], ret[pos2]);
    }
    return ret;
}

bool isSort(const std::vector<int>& nums) {
    for(size_t i = 0; i < nums.size()-1; ++i) {
        if(nums[i] > nums[i+1]) {
            return false;
        }
    }
    return true;
}

void sortTest(const std::string& sortName, 
              const std::function<void(std::vector<int>&)>& sortFunc, 
              std::vector<int>& nums) {
    clock_t start = clock();
    sortFunc(nums);
    clock_t end = clock();

    if(isSort(nums)) {
        std::cout << sortName << " use time: " 
                  << static_cast<double>(end - start) / CLOCKS_PER_SEC 
                  << " s" << std::endl;
    }
    else {
        std::cout << "sort error!" << std::endl;
    }
}

#endif // _TESTHELPER_H

