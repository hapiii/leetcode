//
//  code_34.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/6.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
using  namespace std;

/*
 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

 你的算法时间复杂度必须是 O(log n) 级别。

 如果数组中不存在目标值，返回 [-1, -1]。

 示例 1:

 输入: nums = [5,7,7,8,8,10], target = 8
 输出: [3,4]
 示例 2:

 输入: nums = [5,7,7,8,8,10], target = 6
 输出: [-1,-1]
 */
class code_34 {
    
public:
    
    int getTargetIndex(vector<int>& nums, int target,int left, int right){
        if (left>right) {
            return -1;
        }
        int center = left+ (right-left)/2;
        if (nums[center]<target) {
           return getTargetIndex(nums, target, center+1, right);
        }else if (nums[center] >target) {
           return getTargetIndex(nums, target, left, center-1);
        }else{
            return center;
        }
    };
    vector<int> searchRange(vector<int>& nums, int target) {
         vector<int> end;
        int index = getTargetIndex(nums, target, 0, nums.size()-1);
        if (index == -1) {
            end.push_back(-1);
            end.push_back(-1);
            return end;
        }
        int left = index,right = index;
        
       
        while (left>0 &&nums[left-1] == target) {
            left--;
        }
        while ( right< nums.size()-1 && nums[right+1] == target) {
            right++;
        }
        end.push_back(left);
        end.push_back(right);
        return end;
    }
};
