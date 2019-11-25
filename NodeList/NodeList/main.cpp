//
//  main.cpp
//  NodeList
//
//  Created by hapii on 2019/11/7.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <iostream>
#include "ListNode.cpp"
#include <vector>
#include <set>
using namespace std;
using std::vector;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        set<int> s;
        for (int i = 0;i<nums1.size();i++){
            
            if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end()) {
                s.insert(nums1[i]);
            }
        }
        result.assign(s.begin(), s.end());
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    MyLinkedList *list = new MyLinkedList();
    
    ListNode *head = list->addAtTail(1);
    list->addAtTail(2);
    list->addAtTail(3);
    
    list->removeElements(head, 3);
    list->printList(head);
    
    return 0;
}
