//
//  code_98.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/18.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>

/*
 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 
 假设一个二叉搜索树具有如下特征：
 
 节点的左子树只包含小于当前节点的数。
 节点的右子树只包含大于当前节点的数。
 所有左子树和右子树自身必须也是二叉搜索树。
 示例 1:

 */

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class code_98 {
    
    
public:
    TreeNode* pre;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if(!isValidBST(root->left)){
            return false;
        }
        if(pre && pre->val >= root->val){
            return false;
        }
        pre = root;
        if(!isValidBST(root->right)){
            return false;
        }
        return true;
    }
};
