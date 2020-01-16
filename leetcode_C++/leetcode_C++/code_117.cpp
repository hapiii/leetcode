//
//  code_117.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/14.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
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
class code_117 {
    
    
private:
    vector <vector<Node*>> result;
    
public:
    void helper(Node *root,int level){
        if (result.size() == level) {
            vector<Node*> newRes;
            result.push_back(newRes);
        }
        result[level].push_back(root);
        if (root->left != NULL) {
            helper(root->left, level+1);
        }
        if (root->right != NULL) {
            helper(root->right, level+1);
        }
        
    }
    vector<vector<Node*>> levelOrder(Node* root) {
        if (root == NULL) return result;
        helper(root, 0);
        return result;
    }
    Node* connectt(Node* root) {
        levelOrder(root);
        for (auto arr :result) {
            for (int i = 0; i<arr.size()-1; i++) {
                if (i<arr.size()-2) {
                    arr[i]->next = arr[i+1];
                }
            }
        }
        return root;
    }
 /*
  q.empty()               如果队列为空返回true，否则返回false
  q.size()                返回队列中元素的个数
  q.pop()                 删除队列首元素但不返回其值
  q.front()               返回队首元素的值，但不删除该元素
  q.push()                在队尾压入新元素
  q.back()
  */
    //队列解法
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        queue<Node *>queue;
        queue.push(root);
        while (!queue.empty()) {
            Node *pre = NULL;
            int size = queue.size();
            for (int i = 0; i< size; i++) {
                Node *cur = queue.front();
                queue.pop();
                if (i > 0) {
                    pre->next = cur;
                }
                pre = cur;
                if (cur->left) {
                    queue.push(cur->left);
                }
                if (cur->right) {
                    queue.push(cur->right);
                }
            }
        }
        return root;
    }
    
};
