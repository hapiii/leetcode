//
//  code_155.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/18.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <stack>
using namespace std;


/*
 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 栈的一些函数
 s.empty()               如果栈为空返回true，否则返回false
 s.size()                返回栈中元素的个数
 s.pop()                 删除栈顶元素但不返回其值
 s.top()                 返回栈顶的元素，但不删除该元素
 s.push()                在栈顶压入新元素
 
 push(x) -- 将元素 x 推入栈中。
 pop() -- 删除栈顶的元素。
 top() -- 获取栈顶元素。
 getMin() -- 检索栈中的最小元素。
 */
class MinStack {
private:
    stack<int> minStack;
    stack<int> synStack;
public:
   
    MinStack() {
       
    }
    /*将元素 x 推入栈中*/
    void push(int x) {
        minStack.push(x);
        if (synStack.size() == 0 || synStack.top() >=x) {
            synStack.push(x);
        }else{
            synStack.push(synStack.top());
        }
    }
    /*pop() -- 删除栈顶的元素*/
    void pop() {
        if (!minStack.empty()) {
            minStack.pop();
            synStack.pop();
        }
    }
    /*top() -- 获取栈顶元素*/
    int top() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        return -1;
    }
    /*getMin() -- 检索栈中的最小元素*/
    int getMin() {
        if (!synStack.empty()) {
            return synStack.top();
        }
        return -1;
    }
};


