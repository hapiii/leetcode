//
//  code_429.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/27.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;
    
    Node() {}
    
    Node(int _val) {
        val = _val;
    }
    
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class code_429 {
    
public:
    vector<vector<int>> result;
    void helper(Node *node,int level){
        if (result.size() == level) {
            vector<int> temp;
            result.push_back(temp);
        }
        result[level].push_back(node->val);
        
        if(node->children.size() == 0){
            return;
        }
        for (int i = 0; i<node->children.size(); i++) {
            Node *nextNode = node->children[i];
            helper(nextNode, level+1);
        }
        
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return result;
        helper(root, 0);
        return result;
    };
};
