//
//  code_703.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/15.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <queue>
using namespace std;
/*
 你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用 KthLargest.add，返回当前数据流中第K大的元素。
 
 示例:
 
 int k = 3;
 int[] arr = [4,5,8,2];
 KthLargest kthLargest = new KthLargest(3, arr);
 kthLargest.add(3);   // returns 4
 kthLargest.add(5);   // returns 5
 kthLargest.add(10);  // returns 5
 kthLargest.add(9);   // returns 8
 kthLargest.add(4);   // returns 8
 
 检查优先队列数据结构 维护一个minHeap 队列
 //对于基础类型 默认大顶堆 等同于 priority_queue<int, vector<int>, less<int> > a;
 priority_queue<int> bigQueue;
 //小顶堆
 priority_queue<int, vector<int>, greater<int> > smallQueue;
 
 top 访问队头元素
 empty 队列是否为空
 size 返回队列内元素个数
 push 插入元素到队尾 (并排序)
 emplace 原地构造一个元素并插入队列
 pop 弹出队头元素
 swap 交换内容
 */
class code_703 {
    
    
public:
    
};

class KthLargest {
    //小顶堆
    priority_queue<int, vector<int>, greater<int> > smallHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto num:nums) {
            add(num);
        }
        
    }
    
    int add(int val) {
        if (smallHeap.size() < k) {
            smallHeap.push(val);
        }else if(val > smallHeap.top()){
            smallHeap.pop();
            smallHeap.push(val);
        }
        return smallHeap.top();
    }
};
