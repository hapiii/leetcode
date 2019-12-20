//
//  code_144.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/20.
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

class code_144 {
    
   
private:
     vector<int> result;
public:
    //递归解法:
    /*
     recursive(root);
     return result;
     */
    void recursive(TreeNode* root) {
        if (root != NULL) {
            result.push_back(root->val);
            recursive(root->left);
            recursive(root->right);
        }
        
    }
    
//    TreeNode *getLeftMostRight(TreeNode *root){
//        auto node = root->left;
//        while (node != NULL && node->right != NULL &&node->right != root) {
//            node = node->right;
//        }
//        return node;
//    };
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        while (root) {
            if (root->left == NULL) {
                res.push_back(root->val);
                root = root->right;
            }else{
                auto node = root->left;
                while (node != NULL && node->right != NULL && node->right != root) {
                    node = node->right;
                }
                if (node->right == root) {
                    node->right = NULL;
                    root = root->right;
                }else{
                    res.push_back(root->val);
                    node->right = root;
                    root = root->left;
                }
            }
        }
        return res;
       
    }
};
