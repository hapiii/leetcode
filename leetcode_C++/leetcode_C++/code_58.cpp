//
//  code_58.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/7.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
/*
 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 
 示例:
 
 输入: [0,1,0,3,12]
 输出: [1,3,12,0,0]
 
 */
class code_58{
public:
    //双指针
    void moveZeroes(vector<int>& nums) {
        int tempIndex = 0;
        for (int i = 0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                nums[tempIndex++] = nums[i];
            }
        }
        for ( tempIndex; tempIndex<nums.size(); tempIndex++) {
            nums[tempIndex] = 0;
        }
    }
    
    void moveZeroess(vector<int>& nums) {
        /*  1  0 3 0
            1  0 3 0
            1  0 3 0
            1  3 0 0
         
         */
        
        for (int i = 0,cur = 0; cur<nums.size(); cur++) {
            if (nums[cur] != 0) {
                swap(nums[i++], nums[cur]);
            }
        }
    }
};
