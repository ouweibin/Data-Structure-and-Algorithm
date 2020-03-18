
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : Trie.h
*   Last Modified : 2019-10-04 22:05
*   Describe      :
*
*******************************************************/

#ifndef  _TRIE_H
#define  _TRIE_H

#include <map>
#include <string>

class Trie {
public:
    Trie() :
    root(new Node()),
    count(0) { }

    int size() { return count; }

    void add(const std::string& word) {
        Node* cur = root;
        for(auto& c : word) {
            if(cur->next.find(c) == cur->next.end()) {
                cur->next.insert(std::make_pair(c, Node()));
            }
            cur = &(cur->next.find(c)->second);
        }

        if(!cur->isWord) {
            cur->isWord = true;
            count++;
        }
    }

    bool contains(const std::string& word) {
        Node* cur = root;
        for(auto& c : word) {
            auto iter = cur->next.find(c);
            if(iter == cur->next.end()) {
                return false;
            }
            else {
                cur = &(iter->second);
            }
        }
        return cur->isWord;
    }

    // 是否存在以prefix为前缀的字符串
    bool isPrefix(const std::string& word) {
        Node* cur = root;
        for(auto& c : word) {
            auto iter = cur->next.find(c);
            if(iter == cur->next.end()) {
                return false;
            }
            else {
                cur = &(iter->second);
            }
        }
        return true;
    }


private:
    struct Node {
        bool isWord;
        std::map<char, Node> next; // next[char] = Node

        Node(bool isWord) : 
            isWord(isWord), 
            next() { }
        
        Node() :
            isWord(false),
            next() { }
    };

    Node* root;
    int count;
};

#endif // _TRIE_H

