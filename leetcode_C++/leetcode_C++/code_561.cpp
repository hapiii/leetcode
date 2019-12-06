//
//  code_561.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/6.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

/*
 给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。
 示例 1:
 输入: [1,4,3,2]

 输出: 4
 解释: n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
 */
class code_561 {
    
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int end = 0;
        for (int i = 0; i<nums.size()-1; i += 2) {
            end += nums[i];
        }
        return end;
    }
};
