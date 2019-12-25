//
//  code_106.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/25.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

/*
 根据一棵树的中序遍历与后序遍历构造二叉树。

 注意:
 你可以假设树中没有重复的元素。

 
前序遍历 根->左->右
中序遍历 左->根->右
后续遍历 左->右->根
 
例如，给出
 中序遍历 inorder = [9,3,15,20,7]
 后序遍历 postorder = [9,15,7,20,3]
 
 后续最后一位是root
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
class code_106 {
    
    
public:
    TreeNode* buildTreee(vector<int>& inorder, vector<int>& postorder) {
        int inLen = inorder.size();
        int postLen = postorder.size();
        if (inLen == 0) {
            return nullptr;
        }
        if (inLen == 1) {
            return new TreeNode(inorder[0]);
        }
        int dividepoint = 0;
        TreeNode *root = new TreeNode(postorder[postLen-1]);
        //获取中序的root
        for (int i = 0; i < inLen; i++) {
            if (inorder[i] == postorder[postLen - 1]) {
                dividepoint = i;
                break;
            }
        }
        vector<int> in1(inorder.begin(),inorder.begin()+dividepoint);//9,3
        vector<int> post1(postorder.begin(),postorder.begin()+dividepoint);// 9 15
        
        vector<int> in2(inorder.begin()+dividepoint+1,inorder.begin()+inLen);//15 20 7
        vector<int> post2(postorder.begin()+dividepoint,postorder.begin()+postLen-1);// 7 20 3eeeeee
        root->left = buildTreee(in1, post1);
        root->right = buildTreee(in2, post2);
        return root;
       }
    
    TreeNode* buildhelper(vector<int>& inorder,int inl, int inr ,vector<int>& postorder,int postl,int postr)
    {
        if (inl>inr || postl>postr) {
            return nullptr;
        }
        int rootval = postorder[postr];
        int privot = 0;
        ///找出中序的根
        for (int i = inl; i<inr; i++) {
            if (rootval == inorder[i]) {
                privot = i;
                break;
            }
        }
        TreeNode *root = new TreeNode(rootval);
        //privot-1-inl
        root->left = buildhelper(inorder, inl, privot-1, postorder, postl, privot-1-inl);
        root->right = buildhelper(inorder, privot+1, inr, postorder, postr-inr+privot, postr-1);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder,vector<int> &postorder){
        int length = inorder.size();
        return buildhelper(inorder, 0, length-1, postorder, 0, length-1);
    }
};
