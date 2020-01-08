//
//  code_658.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/6.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
class code_658 {
    
    
public:
    int binarySearch(vector<int>& nums, int target){
        if (nums.size() == 0)
            return -1;
        
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right){
            // Prevent (left + right) overflow
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        // Post-processing:
        // End Condition: left + 1 == right
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        return -1;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = binarySearch(arr, x);
        vector<int> end;
        int max = i>x?i:x;
        for (int m = 0; m < max; m++) {
            end.push_back(arr[m]);
        }
        return end;
    }
};
