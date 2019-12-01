//
//  code_66.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/1.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
/*
 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 
 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 
 你可以假设除了整数 0 之外，这个整数不会以零开头。
 
 示例 1:
 
 输入: [1,2,3]
 输出: [1,2,4]
 解释: 输入数组表示数字 123。
 
 123 +1 124
 999 +1 1000
 */
class code_66 {
    
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1]++;
        for (int i = digits.size()-1; i>=0; i--) {
            if (digits[i]>=10) {
                digits[i] = digits[i]%10;
                if (i==0) {
                    digits.insert(digits.begin(), 1);
                }else{
                    digits[i-1]++;
                }
            }
        }
        return digits;
    }
};
