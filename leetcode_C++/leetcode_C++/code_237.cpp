//
//  code_237.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/26.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
//删除传入的节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class code_237 {
    
    
public:
public:
    void deleteNode(ListNode* node) {
        *node = *(node->next);
//        node->val = node->next->val;
//        node->next = node->next->next;
    }
};
