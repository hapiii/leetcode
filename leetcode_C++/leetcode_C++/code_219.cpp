//
//  code_219.cpp
//  NodeList
//
//  Created by hapii on 2019/11/29.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;

//#219 存在重复元素 II
/*
 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。

 示例 1:

 输入: nums = [1,2,3,1], k = 3
 输出: true

 */
class code_219{
    
public:
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;
        for (int i = 0; i<nums.size(); i++) {
            //如果hash表存在该数字，且 差大于 K,返回yes
            if ( map.count( nums[i] ) != 0  && i-map[nums[i]] <=k) {
                return true;
            }
            // value : index
            map[nums[i]] = i;
        }
        return false;
    }
};
