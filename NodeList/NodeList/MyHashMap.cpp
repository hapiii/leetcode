//
//  MyHashMap.cpp
//  NodeList
//
//  Created by hapii on 2019/11/25.
//  Copyright © 2019 hapii. All rights reserved.
//
//链表实现哈希映射 --拉链法
#include <stdio.h>
#include <vector>
using namespace std;
using std::vector;

struct Node{
    int key;
    int val;
    Node *next;
    Node(int key,int val):key(key),val(val),next(nullptr){}
};
const int len = 100;
class MyHashMap {
public:
    vector<Node *> datas;
    /** Initialize your data structure here. */
    MyHashMap() {
        datas = vector<Node *>(len,new Node(-1,-1));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int haval = key %len;
        Node *node = datas[haval];
        Node *prev = node;
        while (node) {
            if (node->key == key) {
                node->val = value;
                return;
            }
            prev = node;
            node = node->next;
        }
        Node *newNode = new Node(key, value);
        prev->next = newNode;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int haval = key %len;
        Node *node = datas[haval];
        while (node) {
            if (node->key == key) {
                return node->val;
            }
            node = node->next;
        }
        return -1;
    };
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int haval = key %len;
        Node *node = datas[haval];
        Node *pre = node;
        while (node) {
            if (node->key == key) {
                pre->next = node->next;
                return;
            }
            pre = node;
            node = node->next;
        }
       
    }
};

