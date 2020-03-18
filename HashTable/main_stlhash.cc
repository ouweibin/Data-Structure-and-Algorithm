
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_stlhash.cc
*   Last Modified : 2019-10-05 20:41
*   Describe      :
*
*******************************************************/

#include <iostream>
#include <functional>

int main() {
    std::hash<int> hash_int;
    std::hash<float> hash_float;
    std::hash<std::string> hash_string;

    std::cout << hash_int(7) << std::endl;
    std::cout << hash_int(1234567) << std::endl;
    std::cout << hash_float(3.1415926) << std::endl;
    std::cout << hash_string("code") << std::endl;
}


