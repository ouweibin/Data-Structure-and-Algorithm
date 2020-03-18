
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_binarytree.cc
*   Last Modified : 2019-10-05 13:13
*   Describe      :
*
*******************************************************/

#include <iostream>
#include "BinaryTree.h"

void print(const std::string& message, const std::vector<int>& nums) {
    std::cout << message << ": ";
    for(auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> nums = { "5", "4", "8", "11", "null", "13", "4", "7", "2", "null", "null", "null", "1" };
    BinaryTree bt(nums);

    std::cout << "size: "<<bt.size() << std::endl;
    
    std::vector<int> ret;
    ret.clear();
    bt.preOrder(ret);
    print("preOrder", ret);

    ret.clear();
    bt.inOrder(ret);
    print("inOrder", ret);

    ret.clear();
    bt.postOrder(ret);
    print("postOrder", ret);

    ret.clear();
    bt.NRpreOrder(ret);
    print("NRpreOrder", ret);

    ret.clear();
    bt.NRinOrder(ret);
    print("NRinOrder", ret);
     
    ret.clear();
    bt.NRpostOrder(ret);
    print("NRpostOrder", ret);
    
    return 0;
}


