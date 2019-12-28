//
//  code_559.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/28.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
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

class code_559 {
public:
    
    int helper(Node *node,int i){
        int maxVal = i;
        for (int j = 0; j<node->children.size(); j++) {
            maxVal = max(maxVal, helper(node->children[j], i+1));
        }
        return maxVal;
    }
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        return helper(root, 1);
        
    }
};
