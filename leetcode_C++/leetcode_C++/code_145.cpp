//
//  code_145.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/21.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 二叉树的后续遍历
 */
class Solution {
    
private:
    vector<int> result;
public:
    ///递归版本
    void DnorderTraversal(TreeNode* root) {
        if (root != NULL) {
            DnorderTraversal(root->left);
            DnorderTraversal(root->right);
            result.push_back(root->val);
        }
    }
    vector<int> ppostorderTraversal(TreeNode* root) {
        DnorderTraversal(root);
        return result;
    }
    //
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        TreeNode *node = root;
        while (node || stack.size()) {
            while (node) {
                stack.push(node->left);
                res.push_back(node->val);
                node = node->right;
            }
            node = stack.top();
            stack.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
        
    }
    
    
};
