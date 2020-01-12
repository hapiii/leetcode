//
//  code_108.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/12.
//  Copyright © 2020 hapii. All rights reserved.
//
/*
 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 
 二分法递归 逆推中序遍历
 */
#include <stdio.h>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class code_108 {
public:
    
   TreeNode* helper (vector<int>& nums,int left,int right) {
       if (left > right) {
           return NULL;
       }
       int mid = left + (right - left)/2;
       TreeNode *newNode  = new TreeNode(nums[mid]);
       newNode->left = helper(nums, left, mid-1);
       newNode->right = helper(nums, mid+1, right);
       return newNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return helper(nums,0,nums.size()-1);
    }
};
