//
//  code_704.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/31.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
/*
 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 
 示例 1:
 
 输入: nums = [-1,0,3,5,9,12], target = 9
 输出: 4
 解释: 9 出现在 nums 中并且下标为 4
 */
class code_704 {
    
    
public:
    int searchh(vector<int>& nums, int target,int begin,int end) {
        if (begin > end) {
            return -1;
        }
        int center = (begin+end)/2;//这里一定要加括号。。。
        if (nums[center] == target) {
            return center;
        }
        
        if (nums[center] > target) {
            return searchh(nums, target, begin, center-1);
        }else{
            return searchh(nums, target,  center+1, end);
        }
    }
    int search(vector<int>& nums, int target) {
        return searchh(nums, target, 0, nums.size()-1);
    }
};
