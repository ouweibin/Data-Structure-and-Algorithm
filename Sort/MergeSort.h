
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : MergeSort.h
*   Last Modified : 2019-10-09 21:00
*   Describe      :
*
*******************************************************/

#ifndef  _MERGESORT_H
#define  _MERGESORT_H

#include <vector>

void merge(std::vector<int>& nums, int left, int middle, int right) {
    std::vector<int> tmp(right-left+1);
    int i = left;
    int j = middle+1;
    int k = 0;
    while(i <= middle && j <= right) {
        if(nums[i] < nums[j]) {
            tmp[k++] = nums[i++];
        }
        else {
            tmp[k++] = nums[j++];
        }
    }
    while(i <= middle)
        tmp[k++] = nums[i++];
    while(j <= right)
        tmp[k++] = nums[j++];
    
    for(int i = 0; i < k; ++i) {
        nums[left+i] = tmp[i];
    }
}

void mergeSort(std::vector<int>& nums, int left, int right) {
    if(left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(nums, left, middle);
        mergeSort(nums, middle+1, right);
        merge(nums, left, middle, right);
    }
}

void MergeSort(std::vector<int>& nums) {
    mergeSort(nums, 0, nums.size()-1);
}

#endif // _MERGESORT_H

