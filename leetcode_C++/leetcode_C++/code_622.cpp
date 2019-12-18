//
//  code_622.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/18.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
/*
 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
 
 循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
 
 你的实现应该支持如下操作：
 
 MyCircularQueue(k): 构造器，设置队列长度为 k 。
 Front: 从队首获取元素。如果队列为空，返回 -1 。
 Rear: 获取队尾元素。如果队列为空，返回 -1 。
 enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
 deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
 isEmpty(): 检查循环队列是否为空。
 isFull(): 检查循环队列是否已满。
 */

class MyCircularQueue {
    
private:
    int *cycleQueue;
    int size;
    int head;
    int nail;
    
public:
    
    /** 构造器，设置队列长度为 k  */
    MyCircularQueue(int k) {
        size = k + 1;
        cycleQueue = new int[size];
        head = nail = 0;
    }
    
    /** 向循环队列插入一个元素。如果成功插入则返回真 */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        cycleQueue[nail] = value;
        nail = (nail+1)%size;
        return true;
    }
    
    /** 从循环队列中删除一个元素。如果成功删除则返回真 */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = (head+1)%size;
        return true;
    }
    
    /**从队首获取元素。如果队列为空，返回 -1  */
    int Front() {
        return isEmpty() ? -1:cycleQueue[head];
    }
    
    /** 获取队尾元素。如果队列为空，返回 -1 */
    int Rear() {
        return isEmpty() ? -1:cycleQueue[(nail-1+size)%size];//+size 确保为正数
    }
    
    /** 检查循环队列是否为空 */
    bool isEmpty() {
        return head == nail;
    }
    
    /** 检查循环队列是否已满 */
    bool isFull() {
        return (nail+1-head)%size == 0;
    }
};

//vector 实现非循环队列
class NotCircularQueue {
private:
    vector<int > cycleQueue;
    int size;
public:

    /** 构造器，设置队列长度为 k  */
    NotCircularQueue(int k) {
        size = k;
    }
    
    /** 向循环队列插入一个元素。如果成功插入则返回真 */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        cycleQueue.push_back(value);
        return true;
    }
    
    /** 从循环队列中删除一个元素。如果成功删除则返回真 */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        cycleQueue.erase(cycleQueue.begin());
        return true;
    }
    
    /**从队首获取元素。如果队列为空，返回 -1  */
    int Front() {
        return isEmpty() ? -1:cycleQueue[0];
    }
    
    /** 获取队尾元素。如果队列为空，返回 -1 */
    int Rear() {
        return isEmpty() ? -1:cycleQueue[cycleQueue.size()-1];
    }
    
    /** 检查循环队列是否为空 */
    bool isEmpty() {
        return cycleQueue.size() == 0?true:false;
    }
    
    /** 检查循环队列是否已满 */
    bool isFull() {
        return cycleQueue.size() < size ? false:true;
    }
};

