//
//  code_110.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/11.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
#include <unordered_set>
#include <iostream>

struct TreeNode {
        int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    
public:
    ///求最大深度
    int maxDepth(TreeNode* root,int n) {
        if (root == nullptr) {
            return n;
        }
        return fmax(maxDepth(root->left,n+1),maxDepth(root->right,n+1));
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        ///这里递归子节点是否平衡
        return  (abs(maxDepth(root->left,1) - maxDepth(root->right,1))<=1)&&(isBalanced(root->left)&&isBalanced(root->right));
        
       //return depth(root) != -1 ;
    }
    
    ///从底至顶（提前阻断法）
    int depth(TreeNode *root) {
        
        if (root == NULL) {
            return 0;
        }
        int left = depth(root->left);
        if (left == -1) {
            return -1;
        }
        int right = depth(root->right);
        if (right == -1) {
            return right;
        }
       
        if (abs(left - right) < 2) {
             return fmax(left, right) + 1;
        } else {
            return  -1;
        }
    }
    
};
