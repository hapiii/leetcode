//
//  code_225.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/13.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include<queue>

using namespace std;
/*
 使用队列实现栈的下列操作：

 push(x) -- 元素 x 入栈
 pop() -- 移除栈顶元素
 top() -- 获取栈顶元素
 empty() -- 返回栈是否为空
 
 队列的函数
 q.empty()               如果队列为空返回true，否则返回false
 q.size()                返回队列中元素的个数
 q.pop()                 删除队列首元素但不返回其值
 q.front()               返回队首元素的值，但不删除该元素
 q.push()                在队尾压入新元素
 q.back()                返回队列尾元素的值，但不删除该元素  
 
 */
class code_225 {
    
    
public:

};

class MyStack {
    private:
     queue<int> inQueue,outQueue;
    void checkout() {
         
    };
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (inQueue.empty()) {
            inQueue.push(x);
            while (!outQueue.empty()) {
                inQueue.push(outQueue.front());
                outQueue.pop();
            }
        }
    }
    
    /** 移除栈顶元素 */
    int pop() {
        return outQueue.pop();
    }
    
    /** Get the top element. */
    int top() {
        return outQueue.
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
