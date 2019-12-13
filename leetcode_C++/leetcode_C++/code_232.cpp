//
//  code_232.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/13.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <stack>

using namespace std;
/*
 使用栈实现队列的下列操作：

 push(x) -- 将一个元素放入队列的尾部。
 pop() -- 从队列首部移除元素。
 peek() -- 返回队列首部的元素。
 empty() -- 返回队列是否为空。
 
 栈的一些函数
 s.empty()               如果栈为空返回true，否则返回false
 s.size()                返回栈中元素的个数
 s.pop()                 删除栈顶元素但不返回其值
 s.top()                 返回栈顶的元素，但不删除该元素
 s.push()                在栈顶压入新元素

 */
class code_232{
public:
    
};

class MyQueue {
private:
    stack<int> outPutStack;// 输入栈
    stack<int> inPutStack;// 输出栈
    void checkout() {
       if (outPutStack.size() == 0) {
            while (inPutStack.size() != 0) {
                outPutStack.push(inPutStack.top());
                inPutStack.pop();
            };
        }
    };
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
      
    }
    
    /** 将一个元素放入队列的尾部 */
    void push(int x) {
        inPutStack.push(x);
    }
    
    /** 从队列首部移除元素 */
    int pop() {
        checkout();
        int i = outPutStack.top();
        outPutStack.pop();
        return i;
    }
    
    /** 返回队列首部的元素 */
    int peek() {
        checkout();
        return outPutStack.top();
    }
    
    /** 返回队列是否为空 */
    bool empty() {
       checkout();
        return outPutStack.empty();
    }
};
