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
     queue<int> inQueue;
    int topValue;
    void checkout() {
         
    };
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** x 入栈 */
    void push(int x) {
        inQueue.push(x);
        topValue = x;
    }
    
    /** 移除栈顶元素 */
    int pop() {
        queue<int> containerQueue;
        while (inQueue.size() > 1) {
            if (inQueue.size() == 2) {
                topValue = inQueue.front();
            }
            containerQueue.push(inQueue.front());
            inQueue.pop();
        }
       
        int value = inQueue.front();
        inQueue.pop();
        inQueue = containerQueue;
        return value;
    }
    
    /** 获取栈顶元素 */
    int top() {
        return topValue;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return inQueue.size()== 0;
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
