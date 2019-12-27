//
//  code_589.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/26.
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

class code_589 {
    
public:
    vector<int> result;

    void helper(Node* root){
        if(root == NULL) return;
        result.push_back(root->val);//前序递归
        for(Node *node : root->children){
            helper(node);
        }
        // result.push_back(root->val); 后序递归
    }
    vector<int> preorder(Node* root) {
        helper(root);
        return result;
    }
};
