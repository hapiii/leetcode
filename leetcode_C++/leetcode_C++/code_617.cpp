//
//  code_617.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/21.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class code_617 {
    
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL){
            return t2;
        }else if(t2 == NULL){
            return t1;
        }else{
            t1->val = t1->val+t2->val;
        }
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
        return t1;
    }
};
