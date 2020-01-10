//
//  code_700.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/10.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>

/*
 给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。

 例如，

 给定二叉搜索树:

         4
        / \
       2   7
      / \
     1   3

 和值: 2
 你应该返回如下子树:

       2
      / \
     1   3

 */
struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class code_700 {
    
    
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == val) {
            return root;
        }else if (root->val > val) {
           return searchBST(root->left, val);
        }else {
           return searchBST(root->right, val);
        }
    };
};
