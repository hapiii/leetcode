//
//  code_27.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/7.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
/*
 给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
 
 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 
 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 
 示例 1:
 
 给定 nums = [3,2,2,3], val = 3,
 
 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
 
 你不需要考虑数组中超出新长度后面的元素。
 
 */
class code_27 {
    
public:
    int removeElement(vector<int>& nums, int val) {
        int temp = 0;
        for (int cur = 0; cur<nums.size();cur++) {
            if (nums[cur] != val) {
                nums[temp++] = nums[cur];
            }
        }
       
        return temp;
    }
};
