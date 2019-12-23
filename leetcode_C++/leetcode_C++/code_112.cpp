//
//  code_112.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/23.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
/*
 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 
 说明: 叶子节点是指没有子节点的节点。
 
 示例:
 给定如下二叉树，以及目标和 sum = 22，
 
 5
 / \
 4   8
 /   / \
 11  13  4
 /  \      \
 7    2      1
 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
 
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class code_112 {
private:
    
    bool helper(TreeNode* root, int sum){
        if (root == nullptr) {
            return  false;
        }
        sum -= root->val;
        ///这里要加一个判断，假如没有子节点
        if (root->left == NULL&&root->right == nullptr && sum == 0){
            return true;
        }
        return helper(root->left, sum)||helper(root->right, sum);
    };
    
public:
    
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }
        return helper(root, sum);
    }
    
};
