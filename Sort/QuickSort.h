
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : QuickSort.h
*   Last Modified : 2019-10-11 10:27
*   Describe      :
*
*******************************************************/

#ifndef  _QUICKSORT_H
#define  _QUICKSORT_H

#include <vector>

int partition(std::vector<int>& nums, int left, int right) {
    int privot = nums[left];
    int i = left+1;
    int j = right;
    while(true) {
        while(i <= j && nums[i] <= privot) i++;
        while(i <= j && nums[j] >= privot) j--;
        if(i <= j)
            std::swap(nums[i++], nums[j--]);
        else
            break;
    }
    std::swap(nums[left], nums[j]);
    return j;
}

void quickSort(std::vector<int>& nums, int left, int right) {
    if(left < right) {
        int middle = partition(nums, left, right);
        quickSort(nums, left, middle-1);
        quickSort(nums, middle+1, right);
    }
}

void QuickSort(std::vector<int>& nums) {
    quickSort(nums, 0, nums.size()-1);
}

#endif // _QUICKSORT_H

