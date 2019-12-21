//
//  code_94.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/21.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
/*
 给定一个二叉树，返回它的中序 遍历。
 */
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class code_94 {
    
private:
    vector<int> result;
public:
    ///递归版本
    void DnorderTraversal(TreeNode* root) {
        if (root != NULL) {
            DnorderTraversal(root->left);
            result.push_back(root->val);
            DnorderTraversal(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        DnorderTraversal(root);
        return result;
    }
};
