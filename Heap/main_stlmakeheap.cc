
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_stlmakeheap.cc
*   Last Modified : 2019-10-02 20:57
*   Describe      :
*
*******************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

void print(const std::vector<int>& nums) {
    for(auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


int main() {
	std::cout << std::boolalpha;
	srand(static_cast<unsigned int>(time(nullptr)));

	std::vector<int> nums;
	for(int i=0; i < 20; ++i) {
	    nums.push_back(rand() % 100);
	}
	print(nums);

	std::cout << "(1) " << is_heap(nums.begin(), nums.end(), std::greater<int>()) << std::endl;

    // 最小堆
	make_heap(nums.begin(), nums.end(), std::greater<int>());
	print(nums);
	std::cout << "(2) " << is_heap(nums.begin(), nums.end(), std::greater<int>()) << std::endl;

	nums.push_back(50);
	print(nums);
	std::cout << "(3) " << is_heap(nums.begin(), nums.end(), std::greater<int>()) << std::endl;

	push_heap(nums.begin(), nums.end(), std::greater<int>());
	print(nums);
	std::cout << "(4) " << is_heap(nums.begin(), nums.end(), std::greater<int>()) << std::endl;

	pop_heap(nums.begin(), nums.end(), std::greater<int>());
	print(nums);
	std::cout << "(5) " << is_heap(nums.begin(), nums.end(), std::greater<int>()) << std::endl;
	std::cout << "(5) " << is_heap(nums.begin(), nums.end()-1, std::greater<int>()) << std::endl;

	auto ret = nums.back();
	std::cout << ret << std::endl;

	nums.pop_back();
	print(nums);
	std::cout << "(6) " << is_heap(nums.begin(), nums.end(), std::greater<int>()) << std::endl;

	sort_heap(nums.begin(), nums.end(), std::greater<int>());
	print(nums);
}

