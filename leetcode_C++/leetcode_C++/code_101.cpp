//
//  code_101.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/23.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
 给定一个二叉树，检查它是否是镜像对称的。

 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 */
class code_101 {
    
private:
     
public:
    ///左右是否镜像
    bool isMirror(TreeNode *leftNode,TreeNode *rightNode){
        if (leftNode== NULL && rightNode == NULL) {
            return true;
        }
        if (leftNode == NULL || rightNode == NULL) {
            return false;
        }
        return (leftNode->val == rightNode->val)&&
        isMirror(leftNode->left,rightNode->right)&&
        isMirror(leftNode->right, rightNode->left);
    };
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isMirror(root->left,root->right);
    }
};
