//
//  code_113.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/18.
//  Copyright © 2020 hapii. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//DFS 递归
class code_113 {
    
public:
    int tempsum;
    vector<vector<int>> result;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        tempsum = sum;
        vector<int> values;
        if(root == NULL){
            return result;
        }
        helper(root, root->val,values);
        return result;
    }
    
    void helper(TreeNode *node,int curSum,vector<int>valuses){
        
        valuses.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            if (curSum == tempsum) {
            //这里我有一个问题，我只初始化values一次，不应该是一片内存吗，为什么我没有深copy，每条线路的values完全没有影响
                result.push_back(valuses);
            }
            return;
        }
        if (node->left == NULL && node->right) {
            helper(node->right, curSum+node->right->val, valuses);
        }else if (node->right == NULL && node->left) {
            helper(node->left, curSum+node->left->val, valuses);
        }else{
            helper(node->left, curSum+node->left->val, valuses);
            helper(node->right, curSum+node->right->val, valuses);
        }
    };
};
