//
//  code_106.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/25.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

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
    
    unordered_map<int, int> map;
    int index;
    TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
        index = inorder.size() - 1;
        for (int i = 0; i <= index; i++) {
            map[inorder[i]] = i;
        }
        return buildTreeByRecursion(inorder, postorder, 0, index);
    }
    TreeNode * buildTreeByRecursion(vector<int> inorder,vector<int> postorder,int inorder_start,int inorder_end){
        if (inorder_start > inorder_end)
            return NULL;
         //左右根 先拿到根节点的值,确定其在中序遍历的位置，并且将其后序遍历的索引值的末尾往前一位
        int inorder_root = map[postorder[index]];//中序遍历的位置
        TreeNode *root = new TreeNode(postorder[index--]);
        //然后确定左右子树，并且递归即可
        // 注意哦！是必须先递归右子树，再递归左子树，因为后序是左右根的顺序，后序末尾自减一，此时应该是右子树的根节点！
        // 所以必须全部右子树构建完成再去构建左子树
        root->right = buildTreeByRecursion(inorder, postorder, inorder_root + 1,inorder_end);
        root->left = buildTreeByRecursion(inorder, postorder, inorder_start, inorder_root-1);
        return root;
        
    };
};
