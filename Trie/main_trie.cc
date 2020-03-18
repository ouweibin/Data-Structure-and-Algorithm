
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : main_trie.cc
*   Last Modified : 2019-10-04 21:59
*   Describe      :
*
*******************************************************/

#include <iostream>
#include "Trie.h"

int main() {
    Trie trie;
    trie.add("cat");
    trie.add("dog");
    trie.add("deer");
    trie.add("panda");
    trie.add("pan");

    std::cout << std::boolalpha << trie.contains("cat") << std::endl;
    std::cout << std::boolalpha << trie.contains("dog") << std::endl;
    std::cout << std::boolalpha << trie.contains("deer") << std::endl;
    std::cout << std::boolalpha << trie.contains("dee") << std::endl;
    std::cout << std::boolalpha << trie.contains("dot") << std::endl;
    std::cout << std::boolalpha << trie.contains("pan") << std::endl;
    std::cout << std::boolalpha << trie.contains("panda") << std::endl;
    std::cout << "size : " << trie.size() << std::endl;

    return 0;
}


