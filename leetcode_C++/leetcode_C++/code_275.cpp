//
//  code_275.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/23.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

#include<stdio.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class code_257 {
    
public:
    ///递归实现
    vector<string> result;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return result;
        helper(root, "");
        return result;
    }
    void helper(TreeNode* root,string s) {
         int len = s.size();
        s = s+to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            result.push_back(s);
            return;
        }else if(root->left == NULL){
            helper(root->right, s+"->");
        }else if(root->right == NULL){
            helper(root->left, s+"->");
        }else{
            helper(root->left, s+"->");
            helper(root->right, s+"->");
        }
         s.erase(s.begin() + len, s.end());
    }
    
    string path;
   
    vector<string> binaryTreePathss(TreeNode* root) {
        backtrack(root);
        return result;
    }
    void backtrack(TreeNode *node) {
        if (node == NULL) {
            return;
        }
        int len = path.size();
        path +=(path.empty()?"":"->")+to_string(node->val);
        if (node->left == NULL && node->right == NULL) {
            result.push_back(path);
        }else{
            backtrack(node->left);
            backtrack(node->right);
        }
         path.erase(path.begin() + len, path.end());     // 恢复初始状态（擦去新增的长度）
    }
    
};
