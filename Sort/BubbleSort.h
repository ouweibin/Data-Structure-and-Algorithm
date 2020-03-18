
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : BubbleSort.h
*   Last Modified : 2019-10-09 20:05
*   Describe      :
*
*******************************************************/

#ifndef  _BUBBLESORT_H
#define  _BUBBLESORT_H

#include <vector>

void BubbleSort(std::vector<int>& nums) {
    int flag = true;
    for(int i = nums.size()-1; i >= 0; --i) {
        for(int j = 0; j < i; ++j) {
            if(nums[j] > nums[j+1]) {
                flag = false;
                std::swap(nums[j], nums[j+1]);
            }
        }
        if(flag) {
            return;
        }
        else {
            flag = true;
        }
    }
}

#endif // _BUBBLESORT_H

