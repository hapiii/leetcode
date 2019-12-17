//
//  code_15.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/17.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

 注意：答案中不可以包含重复的三元组。

 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

 满足要求的三元组集合为：
 [
   [-1, 0, 1],
   [-1, -1, 2]
 ]
 */
class code_15 {
    
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result = {};
        if (nums.size() == 0 || nums.size() <3) {
            return result;
        }
        int length = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i<length; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 &&nums[i] == nums[i-1]) {//去重
                continue;
            }
            int left =i+1;
            int right = length-1;
            while (left < right) {
                int sum = nums[i]+nums[left]+nums[right];
                if (sum<0) {
                    left++;
                }else if (sum > 0){
                    right--;
                }else{
                    result.push_back({nums[i],nums[left],nums[right]});
                   //去重
                    while (left < right && nums[left] == nums[++left]);
                    while (left < right && nums[right] == nums[--right]);
                }
            }
        }
        return result;
        
    }
};
