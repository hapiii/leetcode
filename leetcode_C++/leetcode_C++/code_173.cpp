//
//  code_173.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/9.
//  Copyright © 2020 hapii. All rights reserved.
//

/*
 实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。

 调用 next() 将返回二叉搜索树中的下一个最小的数。
 */
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
///中序遍历
class BSTIterator {
public:
    
    vector<int> treeArr;
    BSTIterator(TreeNode* root) {
        addToArr(root);
    }
    
    void addToArr(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        addToArr(root->left);
        treeArr.push_back(root->val);
        addToArr(root->right);
    }
    
    int next() {
        int i = treeArr[0];
        treeArr.erase(treeArr.begin());
        return i;
        
    }

    bool hasNext() {
        return treeArr.size()== 0? false:true;
    }
};
*/

/*
class BSTIterator {
private:
    queue<int> que;
public:
    BSTIterator(TreeNode* root) {
        inordesort(root);
    }
    
    int next() {
        int frontval = que.front();
        que.pop();
        return frontval;
    }
    
    bool hasNext() {
        return !que.empty();
    }
private:
    void inordesort(TreeNode * root)
    {
        if(root != NULL)
        {
            inordesort(root->left);
            que.push(root->val);
            inordesort(root->right);
        }
    }
};
*/

class BSTIterator {
    
private:
    TreeNode* curr;
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        curr = root;
        while (!s.empty())
            s.pop();
    }

    /** @return the next smallest number */
    int next() {
        if (hasNext()) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
        } else {
            return -1;
        }
        int res = curr->val;
        curr = curr->right;
        return res;
    }
    

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty() || curr != NULL;
    }
};

