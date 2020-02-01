//
//  code_169.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/2/1.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 示例 1:

 输入: [3,2,3]
 输出: 3

 解法1:暴力法
 解法2:hash
 解法3:排序
 解法4:分治
 解法5:Boyer-Moore 投票
 */
class code_169 {
    
    
public:
    
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int > hash;
        int temp = 0;
        for (auto num :nums) {
            hash[num]++;
            if (hash[num] > nums.size()/2) {
                temp = num;
                return temp;
            }
        }
        return temp;
    }
    
    //投票算法
    int majorityElementt(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for (auto num :nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
