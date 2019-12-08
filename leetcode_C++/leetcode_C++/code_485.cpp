//
//  code_485.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/8.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

/*
 给定一个二进制数组， 计算其中最大连续1的个数。
 
 示例 1:
 
 输入: [1,1,0,1,1,1]
 输出: 3
 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
 
 */
class code_485 {
    
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int end = 0,temp = 0;
        for (auto num:nums) {
            if (num == 1) {
                temp++;
            }else{
                end = temp>end?temp:end;
                temp = 0;
            }
        }
        end = temp>end?temp:end;
        return end;
    }
};
