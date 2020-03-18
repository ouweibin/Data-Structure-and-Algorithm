
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : OpenHashTable.h
*   Last Modified : 2019-10-09 18:52
*   Describe      :
*
*******************************************************/

#ifndef  _OPENHASHTABLE_H
#define  _OPENHASHTABLE_H

#include <iostream>
#include <functional>

template <typename Key, typename Value>
struct HashNode {
    Key key;
    Value value;
    HashNode* next;

    HashNode() :
        key(),
        value(),
        next(nullptr) { }

    HashNode(Key key, Value value, HashNode* next) :
        key(key),
        value(value),
        next(next) { }
};

template <typename Key, typename Value>
class OpenHashTable {
public:
    OpenHashTable(int divisor = 97) :
        divisor(divisor),
        count(0) {
        ht = new HashNode<Key, Value>[divisor];
    }

    ~OpenHashTable() {
        for(int i = 0; i < divisor; ++i) {
            HashNode<Key, Value>* p = ht[i].next;
            while(p != nullptr) {
                ht[i].next = p->next;
                delete p;
                p = ht[i].next;
            }
        }
        delete[] ht;
    }

    int size() { return count; }

    void insert(Key key, Value value) {
        int index = hash(key);
        HashNode<Key, Value>* p = search(key);
        if(p == nullptr) {
            ht[index].next = new HashNode<Key, Value>(key, value, ht[index].next);
            count++;
        }
        else {
            p->value = value;   // 更新
        }
    }

    void remove(Key key) {
        int index = hash(key);
        HashNode<Key, Value>* cur = ht[index].next;
        HashNode<Key, Value>* pre = &ht[index];
        while(cur != nullptr && cur->key != key) {
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = cur->next;
        cur->next = nullptr;
        delete cur;
    }

    void set(Key key, Value value) {
        HashNode<Key, Value>* p = search(key);
        p->value = value;
    }

    Value get(Key key) {
        HashNode<Key, Value>* p = search(key);
        return p->value;
    }

    bool contains(Key key) {
        return search(key) != nullptr;
    }

    void display() {
        for(int i = 0; i < divisor; ++i) {
            std::cout << i << ":  ";
            HashNode<Key, Value>* p = ht[i].next;
            while(p != nullptr) {
                std::cout << p->key << ":" << p->value << "  ";
                p = p->next;
            }
            std::cout << std::endl;
        }
    }

private:
    int hash(Key key) {
        std::hash<Key> key_hash;
        return static_cast<int>(key_hash(key) % divisor);
    }

    HashNode<Key, Value>* search(Key key) {
        int index = hash(key);
        HashNode<Key, Value>* p = ht[index].next;
        while(p != nullptr && p->key != key) {
            p = p->next;
        }
        return p;
    }

private:
    int divisor;
    int count;
    HashNode<Key, Value>* ht;  // 虚拟节点
};

#endif // _OPENHASHTABLE_H

