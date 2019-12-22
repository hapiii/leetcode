//
//  code_104.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/22.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <unordered_set>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class code_104{
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
