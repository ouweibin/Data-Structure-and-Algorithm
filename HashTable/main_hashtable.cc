
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_hashtable.cc
*   Last Modified : 2019-10-09 17:18
*   Describe      :
*
*******************************************************/

#include <vector>
#include <cassert>

#include "OpenHashTable.h"

int main() {
	std::vector<int> keys = { 32, 40, 36, 53, 16, 46, 71, 27, 42, 24, 49, 64 };
	std::vector<int> values = { 32, 40, 36, 53, 16, 46, 71, 27, 42, 24, 49, 64 };
		
	OpenHashTable<int, int> ht(13);
	for(int i = 0; i < 12; ++i) {
		ht.insert(keys[i], values[i]);
	}
	ht.display();

    ht.remove(53);
    ht.display();

    ht.set(16, 61);
    ht.display();

    std::cout << ht.get(16) << std::endl;
    std::cout << ht.get(36) << std::endl;

	assert(ht.contains(27));

	return 0;
}

