//
//  code_102.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/22.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class code_102 {
private:
    vector <vector<int>> result;
public:
    void DFS(TreeNode *root,int level){
        if (result.size() == level) {
            vector<int> newRes;
            result.push_back(newRes);
        }
        result[level].push_back(root->val);
        if (root->left != NULL) {
            DFS(root->left, level+1);
        }
        if (root->right != NULL) {
            DFS(root->right, level+1);
        }
    }
    vector<vector<int>> levelOrderr(TreeNode* root) {
        if (root == NULL) return result;
        DFS(root, 0);
        return result;
    }
    
    ///BFS 广度优先搜索解法
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector<int>> end;
        if (root == NULL) return end;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            int level_size = queue.size();
            vector<int> current_level;
            for (int i = 0; i<level_size; i++) {
                TreeNode *node = queue.front();
                queue.pop();
                current_level.push_back(node->val);
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            end.push_back(current_level);
        }
        return end;
    }
    
    
};
