//
//  code_116.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/15.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    
    Node(int _val, Node* _left, Node* _right, Node* _next)
    : val(_val), left(_left), right(_right), next(_next) {}
};
class code_116 {
    
    
public:
    Node* connect(Node* root) {
        if (!root) return root;
        Node * left = root->left;
        Node * right = root->right;
        while(left) {
            left->next = right;
            left = left->right;
            right = right->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
    
    //方法2:记录上级节点遍历
    Node* connectt(Node* root) {
        if (!root) return NULL;
        auto start = root;
        while (start->left) {
            auto pre = start, cur = pre->next;
            while (pre) {
                pre->left->next = pre->right;
                if (cur) pre->right->next = cur->left;
                
                // 下一趟
                pre = cur;
                if (cur) cur = cur->next;
            }
            start = start->left;
        }
        return root;
    }
    
    Node* connecct(Node* root) {
        if (root == nullptr) {
            return root;
        }
        Node *start = root;
        while (start->left) {
            Node *pre = start;//记录上一个节点
            Node *cur = pre->next;//当前节点
            while (pre) {
                pre->left->next = pre->right;
                if (cur) {
                    pre->right->next = cur->left;
                }
                pre = cur;
                if (cur) {
                    cur = cur->next;
                }
            }
            start = start->left;
        }
        return root;
    }
    
};

