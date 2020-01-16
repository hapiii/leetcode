//
//  code_226.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/16.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class code_226 {
    
public:
    TreeNode *temp;
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)return root;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
