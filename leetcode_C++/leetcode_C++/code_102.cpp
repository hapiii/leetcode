//
//  code_102.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/22.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class code_102 {
private:
    vector <vector<int>> result;
public:
    void helper(TreeNode *root,int level){
        if (result.size() == level) {
            vector<int> newRes;
            result.push_back(newRes);
        }
        result[level].push_back(root->val);
        if (root->left != NULL) {
            helper(root->left, level+1);
        }
        if (root->right != NULL) {
            helper(root->right, level+1);
        }
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return result;
        helper(root, 0);
        return result;
    }
};
