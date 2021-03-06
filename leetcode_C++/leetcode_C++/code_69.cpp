//
//  code_69.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/1.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
/*
 实现 int sqrt(int x) 函数。

 计算并返回 x 的平方根，其中 x 是非负整数。

 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

 示例 1:

 输入: 4
 输出: 2
 示例 2:

 输入: 8
 输出: 2
 说明: 8 的平方根是 2.82842...,
      由于返回类型是整数，小数部分将被舍去。
 */

class code_69 {
    
    
public:
    int mySqrt(int x) {
        
        int left = 0,right = x;
        int center = 0;
        while (left<= right) {
            center = left+(right-left)/2;
            if (center*center <= x && (center+1)*(center+1)>x) {
                return center;
            }else if (center*center > x) {
                right = center-1;
            }else{
                left = center+1;
            }
        }
        return center;
    }
};
