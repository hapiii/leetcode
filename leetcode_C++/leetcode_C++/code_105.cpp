//
//  code_105.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/13.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 根据一棵树的前序遍历与中序遍历构造二叉树。

 注意:
 你可以假设树中没有重复的元素。

 例如，给出

 前序遍历 preorder = [3,9,20,15,7]
 中序遍历 inorder = [9,3,15,20,7]
 返回如下的二叉树：

     3
    / \
   9  20
     /  \
    15   7
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
        
    }
};

class code_105 {
    
    
public:
    
    int index;
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index = 0;
        for (int i = 0; i <= inorder.size() - 1; i++) {
            map[inorder[i]] = i;
        }
        return helper(preorder, inorder, index, inorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int inorderBegin,int inorderEnd) {
        if (inorderBegin > inorderEnd) {
            return NULL;
        }
        int i = map[preorder[index]];
        
        TreeNode *root = new TreeNode(preorder[index--]);
        root->right = helper(preorder,inorder,i+1,inorderEnd);
        root->left = helper(preorder,inorder,inorderBegin,i-1);
        
        return root;
    };
};
