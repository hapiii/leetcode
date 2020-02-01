//
//  code_236.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/20.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
/*
 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 
 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 
 例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
 
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return ans;
    }
    bool helper(TreeNode* node, TreeNode* p, TreeNode* q){
        if (node == NULL) {
            return false;
        }
        int left = helper(node->left, p, q)? 1:0;
        int right = helper(node->right, p, q)?1:0;
        int mid = (node == p || node == q) ? 1 : 0;
        if (left+mid+right >= 2) {
            ans = node;
        }
         return (mid + left + right > 0);
    }
};
