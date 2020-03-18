
/******************************************************
*   Copyright (C)2019 All rights reserved.
*
*   Author        : owb
*   Email         : 2478644416@qq.com
*   File Name     : BinaryTree.h
*   Last Modified : 2019-10-09 11:12
*   Describe      :
*
*******************************************************/

#ifndef  _BINARYTREE_H
#define  _BINARYTREE_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

class BinaryTree {
public:
    BinaryTree(const std::vector<std::string>& nums) :
        root(nullptr),
        count(0) {
        if(nums.size() == 0 || nums[0] == "null")
            return;
       
        root = new TreeNode(stoi(nums[0]));
        count++;

        std::queue<TreeNode*> q;
        q.push(root);

        // 从第2层开始
        int curLevelNodeNum = 2;       // 第2层有2个节点
        int curLevelStartIndex = 1;    // nums[curLevelStartIndex]
        int remainNodeNum = nums.size() - 1;

        while(remainNodeNum > 0) {
            for(int i = curLevelStartIndex; i < curLevelStartIndex + curLevelNodeNum; i += 2) {
                if(i == static_cast<int>(nums.size())) {
                    return;
                }
                TreeNode* cur = q.front();
                q.pop();

                if(nums[i] != "null") {
                    cur->left = new TreeNode(stoi(nums[i]));
                    count++;
                    q.push(cur->left);
                }

                if(i+1 == static_cast<int>(nums.size())) {
                    return;
                }
                if(nums[i+1] != "null") {
                    cur->right = new TreeNode(stoi(nums[i+1]));
                    count++;
                    q.push(cur->right);
                }
            }

            curLevelStartIndex += curLevelNodeNum;
            remainNodeNum -= curLevelNodeNum;
            curLevelNodeNum = q.size() * 2;
        }
    }

    TreeNode* getRoot() { return root; }
    int size() { return count; }

    void preOrder(std::vector<int>& ret) { preOrder(root, ret); }
    void inOrder(std::vector<int>& ret) { inOrder(root, ret); }
    void postOrder(std::vector<int>& ret) { postOrder(root, ret); }

    void NRpreOrder(std::vector<int>& ret) {
//        std::stack<TreeNode*> s;
//        s.push(root);
//        while(!s.empty()) {
//            TreeNode* node = s.top();
//            s.pop();
//            ret.push_back(node->val);
//            if(node->right) {
//                s.push(node->right);  // 先放右孩子，再放左孩子
//            }
//            if(node->left) {
//                s.push(node->left);
//            }
//        }
        std::stack<TreeNode*> s;
        TreeNode* p = root;
        while(p != nullptr || !s.empty()) {
            while(p != nullptr) {
                ret.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            if(!s.empty()) {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
    }

    void NRinOrder(std::vector<int>& ret) {
        std::stack<TreeNode*> s;
        TreeNode* p = root;
        while(p != nullptr || !s.empty()) {
            if(p) {
                s.push(p);
                p = p->left;
            }
            else {
                p = s.top();
                s.pop();
                ret.push_back(p->val);
                p = p->right;
            }
        }
//        std::stack<TreeNode*> s;
//        TreeNode* p = root;
//        while(p != nullptr || !s.empty()) {
//            while(p != nullptr) {
//                s.push(p);
//                p = p->left;
//            }
//            if(!s.empty()) {
//                p = s.top();
//                s.pop();
//                ret.push_back(p->val);
//                p = p->right;
//            }
//        }
    }

    void NRpostOrder(std::vector<int>& ret) {
        std::stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            ret.push_back(node->val);
            if(node->left) {
                s.push(node->left);
            }
            if(node->right) {
                s.push(node->right);
            }
        }
        std::reverse(ret.begin(), ret.end());
    }

private:
    void preOrder(TreeNode* node, std::vector<int>& ret) {
        if(node == nullptr)
            return;

        ret.push_back(node->val);
        preOrder(node->left, ret);
        preOrder(node->right, ret);
    }

    void inOrder(TreeNode* node, std::vector<int>& ret) {
        if(node == nullptr)
            return;

        inOrder(node->left, ret);
        ret.push_back(node->val);
        inOrder(node->right, ret);
    }

    void postOrder(TreeNode* node, std::vector<int>& ret) {
        if(node == nullptr)
            return;

        postOrder(node->left, ret);
        postOrder(node->right, ret);
        ret.push_back(node->val);
    }

private:
    TreeNode* root;
    int count;
};

#endif // _BINARYTREE_H

