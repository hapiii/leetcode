//
//  code_153.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/5.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

/*
 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 
 ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 
 请找出其中最小的元素。
 
 你可以假设数组中不存在重复元素。
 
 输入: [2,3,4,5,1]
 输出: 1
 
 输入: [5,6,1,2,3,4]
 输出: 1
 */
class code_153 {
    
    
public:
    void test(){
        vector<int> v1;
        v1.push_back(5);
        v1.push_back(6);
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        
        findMin(v1);
    }
    int findMin(vector<int>& nums) {
        int left = 0,right = nums.size()-1;
        int center,temp;
        int end = nums[0];
        
        while (left <= right) {
            center = left+ (right-left)/2;
            if(end>nums[center]){
                end = nums[center];
            }
            if (nums[left] < nums[center] ) {
                left = center;
            }else if (nums[center] < nums[right] ) {
                right = center;
            }else{
                temp = nums[left]<nums[right]?nums[left]:nums[right];
                return end<temp?end:temp;
            }
        }
        return end;
    }
};
