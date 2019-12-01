//
//  code_747.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/1.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
/*
 在一个给定的数组nums中，总是存在一个最大元素 。
 
 查找数组中的最大元素是否至少是数组中每个其他数字的两倍。
 
 如果是，则返回最大元素的索引，否则返回-1。
 
 示例 1:
 
 输入: nums = [3, 6, 1, 0]
 输出: 1
 解释: 6是最大的整数, 对于数组中的其他整数,
 6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.
  
 */

class code_747 {
    
    
public:
    
    int dominantIndex(vector<int>& nums) {
        int maxIndex = -1;
        int secondValue = -1;
        int maxValue = -1;
        for (int i = 0; i<nums.size(); i++) {
            if (nums[i] > maxValue) {
                secondValue = maxValue;
                maxValue = nums[i];
                maxIndex = i;
            }else if (nums[i]>secondValue && nums[i] < maxValue) {
                secondValue = nums[i];
            }
        }
        if (maxValue >= secondValue*2) {
            return maxIndex;
        }else{
            return -1;
        }
    }
};
