//
//  code_162.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/4.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>

#include <vector>
using namespace std;
class code_162 {
    
    
public:
    int mid;
    int helper(vector<int>& nums, int left,int right){
        if (left>right) {
            return -1;
        }
        if (nums.size() == 1) {
            return 0;
        }
        mid = left+(right-left)/2;
        if (mid -1 < 0&& nums[mid+1]<nums[mid]) {///[3,2,1]这种情况
            return mid;
        }
        if (mid +1 >= nums.size() && nums[mid-1]<nums[mid]) {///[3,2,1]这种情况
            return mid;
        }
        if (mid+1<nums.size()&&mid>=1&& nums[mid+1]<nums[mid]&&nums[mid-1]<nums[mid]) {
            return mid;
        };
        int l = helper(nums, mid+1, right);
        int r = helper(nums, left, mid-1);
        if (l == -1 && r == -1) {
            return -1;
        }
        return l == -1?r:l;
    };
    int findPeakElement(vector<int>& nums) {
       return helper(nums, 0, nums.size() - 1);
    }
};
