//
//  code_367.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/7.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>

/*
 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

 说明：不要使用任何内置的库函数，如  sqrt。

 示例 1：

 输入：16
 输出：True
 */
class code_367 {
    
    
public:
    
    
    bool isPerfectSquare(int num) {
        long int left = 0,right = num;
        int mid;
        long int end;
        while (left <= right) {
            mid = left+(right-left)/2;
            end = mid*mid;
            if(end == num){
                return true;
            } else if (end <num) {
                left = mid+1;
            }else{
                right = mid - 1;
            }
        }
        return false;
    }
};
