//
//  code_239.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/16.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <deque>
using namespace std;
/*
 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

 返回滑动窗口中的最大值。

  

 示例:

 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
 输出: [3,3,5,5,6,7]
 解释:

   滑动窗口的位置                最大值
 ---------------               -----
 [1  3  -1] -3  5  3  6  7       3
  1 [3  -1  -3] 5  3  6  7       3
  1  3 [-1  -3  5] 3  6  7       5
  1  3  -1 [-3  5  3] 6  7       5
  1  3  -1  -3 [5  3  6] 7       6
  1  3  -1  -3  5 [3  6  7]      7

 
 检查优先队列数据结构 维护一个maxHeap 队列
 
 C++函数：
 //对于基础类型 默认大顶堆 等同于 priority_queue<int, vector<int>, less<int> > a;
 priority_queue<int> bigQueue;
 //小顶堆
 priority_queue<int, vector<int>, greater<int> > smallQueue;
 双端队列
 deque
 
 c.assign(beg,end) 将[beg; end)区间中的数据赋值给c。

 c.assign(n,elem) 将n个elem的拷贝赋值给c。

 c. at(idx) 传回索引idx所指的数据，如果idx越界，抛出out_of_range。

 c.back() 传回最后一个数据，不检查这个数据是否存在。

 c.begin() 传回迭代器中的第一个数据。

 c.clear() 移除容器中所有数据。

 c.empty() 判断容器是否为空。

 c.end() 指向迭代器中的最后一个数据地址。

 c.erase(pos) 删除pos位置的数据，传回下一个数据的位置。

 c.erase(beg,end) 删除[beg,end)区间的数据，传回下一个数据的位置。

 c.front() 传回第一个数据。

 get_allocator 使用构造函数返回一个拷贝。

 c.insert(pos,elem) 在pos位置插入一个elem拷贝，传回新数据位置

 c.insert(pos,n,elem) 在pos位置插入>n个elem数据。无返回值

 c.insert(pos,beg,end) 在pos位置插入在[beg,end)区间的数据。无返回值

 c.max_size() 返回容器中最大数据的数量。

 c.pop_back() 删除最后一个数据。

 c.pop_front() 删除头部数据。

 c.push_back(elem) 在尾部加入一个数据。

 c.push_front(elem) 在头部插入一个数据。

 c.rbegin() 传回一个逆向队列的第一个数据。
 */
class code_239 {
    
    
public:
    
};

class MonotonicQueue {
private:
    
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> window;
        vector <int> result;
        
        for (int i = 0; i <nums.size(); i++) {
            if (i < k-1) {
                //删除队列中比n小的
                while (!window.empty() && window.back() < nums[i]) {
                    window.pop_back();
                }
                window.push_back(nums[i]);
            }else{
               
                while (!window.empty() && window.back() < nums[i]) {
                    window.pop_back();
                }
                window.push_back(nums[i]);
                
                result.push_back(window.front());
                //删除前一个元素
                if (!window.empty() && window.front() == nums[i-k+1]) {
                    window.pop_front();
                }
            }
        }
        return result;
    };
    //暴力法
    /*
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return nums;
        }
        vector<int> result;
        vector<int> window;
        for (int i = 0; i<k; i++) {
            window.push_back(nums[i]);
        }
        for (int i = k; i<nums.size()+1; i++) {
            int j = *max_element(begin(window), end(window));
            result.push_back(j);
            if (i<nums.size()) {
                window.erase(window.begin());
                window.push_back(nums[i]);
            }
        }
        
        return result;
    }
     */
};
