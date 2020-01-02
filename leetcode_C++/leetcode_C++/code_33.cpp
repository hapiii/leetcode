//
//  code_33.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/1.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
/*
 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

 ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

 你可以假设数组中不存在重复的元素。

 你的算法时间复杂度必须是 O(log n) 级别。

 示例 1:

 输入: nums = [4,5,6,7,0,1,2], target = 0
 输出: 4

 
 数组从任意位置劈开后，至少有一半是有序的，什么意思呢？

 比如 [ 4 5 6 7 1 2 3] ，从 7 劈开，左边是 [ 4 5 6 7] 右边是 [ 7 1 2 3]，左边是有序的。


 */
class code_33 {
    
   
public:
    
    void test(){
        vector<int> v1;
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);
        v1.push_back(6);
        v1.push_back(1);
        v1.push_back(2);

        search(v1, 2);
    }
    
   /*561 234*/
    int search(vector<int>& nums, int target) {
       
        int left = 0,right = nums.size()-1;
        int  mid = left+(right-left)/2;
        while (left <= right) {
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) {///有序
                if (target >= nums[left] && target <= nums[mid]) {
                    right = mid-1;///在范围内，则二分
                }else{
                    left = mid+1;//不在范围内，到另一个数组
                }
            }else{
                if (target >= nums[mid] && target<=nums[right]) {
                    left = mid+1;
                }else{
                    right = mid -1;
                }
            }
            mid = left+(right-left)/2;
        }
        return -1;
    }
    
};


/*
 class Solution {
 public:
      int center;
     int tag = -1;
    int helper(vector<int>& nums, int target,int left,int right,bool knowTag) {
             
         if (nums.size() == 0 ) {
             return -1;
         }
         center = left+(right-left)/2;
         if (nums[center] == target) {
             return center;
         }
         if (left >= right ){
             return -1;
         }
         if (center <= nums.size()-2 &&nums[center] >= nums[center+1]) {
             tag = center+1;
         }
         if (center >= 1 &&nums[center-1] >= nums[center]) {
             tag = center;
         }
         if (tag< 0 || knowTag) {
             if (nums[center]<target) {
                  return  helper(nums, target, center+1, right,knowTag);
             }else{
               return  helper(nums, target, left, center-1,knowTag);
             }
         }else{
             if (nums[nums.size()-1]<target) {
                  return  helper(nums, target, left, tag-1,true);
             }else{
               return  helper(nums, target, tag, right,true);
             }
         }
     }
     
     int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size()-1,false);
     }
 };
 */
