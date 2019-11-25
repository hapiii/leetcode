//
//  MyHashSet.cpp
//  NodeList
//
//  Created by hapii on 2019/11/25.
//  Copyright © 2019 hapii. All rights reserved.
//

#include "MyHashSet.hpp"
#include <vector>
using namespace std;
using std::vector;

struct Node{
    int val;
    Node *next;
    Node(int val):val(val),next(nullptr){}
};
const int len = 100;
class MyHashSet {
    
public:
    
    vector<Node *>arr;
    /** Initialize your data structure here. */
    MyHashSet() {
        arr = vector<Node *>(len,new Node(-1));
    }
    
    void add(int key) {
        int haval = key %len;
        Node *temp = arr[haval];
        if (temp->val != -1) {
            while (temp) {
                if(temp->val == key) return;
                if (temp->next == nullptr) {
                    Node *node = new Node(key);
                    temp->next = node;
                    return;
                }
                temp = temp->next;
            }
        }else{
            temp->val = key;
            return;
        }
    }
    
    void remove(int key) {
        int haval = key%len;
        Node *temp = arr[haval];
        if (temp->val != -1) {
            while (temp) {
                if (temp->next->val == key) {
                    Node *deleNode = temp->next;
                    temp->next = temp->next->next;
                    deleNode = nullptr;
                    return;
                }
                temp = temp->next;
            }
        }
        
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int haval = key%len;
        Node *temp = arr[haval];
        if (temp->val != -1) {
            while (temp) {
                if (temp->val == key) {
                    return true;
                }
                temp = temp->next;
            }
        }
        return false;
    }
};
