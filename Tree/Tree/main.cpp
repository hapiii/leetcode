//
//  main.cpp
//  Tree
//
//  Created by hapii on 2019/11/18.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <iostream>
#include <wchar.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
///是否是相同的二叉树
bool isSameTree(TreeNode* p, TreeNode* q ) {
   if(p==nullptr && q==nullptr){
         return true;
     }
    if( p != nullptr && q != nullptr && p->val == q->val) {
         return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
     }else{
         return false;
     }
}
///二叉树的最大深度
int maxDepth(TreeNode* root) {
    return 3;
};

int main(int argc, const char * argv[]) {
    TreeNode *node = new TreeNode(1);
    TreeNode *leftNode = new TreeNode(2);
    TreeNode *rightNode = new  TreeNode(3);
    node->left = leftNode;
    node->right = rightNode;
    
    bool isOk =  isSameTree(node, node);
    std::cout<<isOk;
    return 0;
}
