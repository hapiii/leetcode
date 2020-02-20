//
//  code_111.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/18.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
#include <unordered_set>
/*
 给定一个二叉树，找出其最小深度。

 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

 说明: 叶子节点是指没有子节点的节点。

 示例:

 给定二叉树 [3,9,20,null,null,15,7],=》返回2

     3
    / \
   9  20
     /  \
    15   7

 给定二叉树 [3,9,20,9,null,null,7], =》返回3

     3
    / \
   9  20
  /     \
 9       7
 
 这个题一定要搞清楚题意 从根节点到最近叶子节点 3-9 中的9并不算叶子节点，所以并不是最短路径
 
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class code_111 {
    
    
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (!root->left) return minDepth(root->right)+1;
        if (!root->right) return minDepth(root->left)+1;
        return fmin(minDepth(root->left),minDepth(root->right)) + 1;
        //return helper(root, 1);
    }
    
    int helper(TreeNode *node,int depth){
        if(node == NULL){
            return depth-1;
        }
        depth++;
        if (node->left == NULL && node->right != NULL) {
            return helper(node->right,depth );
        }
        if (node->right == NULL && node->left != NULL) {
            return helper(node->left,depth );
        }
        return fmin(helper(node->left,depth ),helper(node->right, depth));
    }
};
