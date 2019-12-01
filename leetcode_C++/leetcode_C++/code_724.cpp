//
//  code_724.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/11/30.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

/*
 给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。
 
 我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
 
 如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
 
 示例 1:
 
 输入:
 nums = [1, 7, 3, 6, 5, 6]
 输出: 3
 解释:
 索引3 (nums[3] = 6) 的左侧数之和(1 + 7 + 3 = 11)，与右侧数之和(5 + 6 = 11)相等。
 同时, 3 也是第一个符合要求的中心索引。
 
 */
class code_724 {
    
public:
    int pivotIndexx(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        int left;
        int right = 0;
        for (int i=1;i<nums.size();i++){
            right += nums[i];
        }
        for (int i=0;i<nums.size() -1 ;i++){
            if (right == left) return i;
            right = right - nums[i+1];
            left += nums[i];
        }
        if (left==right) return nums.size() - 1;
        else return -1;
    }
    
    int pivotIndex(vector<int>& nums) {
       
        int sum = 0;
        for (auto num :nums) {
            sum += num;
        }
        int indexSum = 0;
        for (int i = 0; i<nums.size(); i++) {
           
            if (indexSum == sum - indexSum - nums[i]) {
                return i;
            }
             indexSum += nums[i];
        }
        return -1;
    }
    
};
