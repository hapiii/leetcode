//
//  code_202.cpp
//  NodeList
//
//  Created by hapii on 2019/11/29.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>

/*
 编写一个算法来判断一个数是不是“快乐数”。
 
 一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。
 
 示例:
 
 输入: 19
 输出: true
 解释:
 12 + 92 = 82
 82 + 22 = 68
 62 + 82 = 100
 12 + 02 + 02 = 1
 
 不是快乐数 最终会 4 16 37 58 89 145 42 20
 */
class code_202 {
    
public:
    int bitSquareSum(int n){
        int sum = 0;
        while (n>0) {
            int bit = n%10;
            sum += bit*bit;
            n = n/10;
        }
        return sum;
    }
    ///快慢指针
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        } while (slow!= fast);
        
        return slow == 1;
    }
    ///递归解法
    bool isHappyy(int n) {
        int m = n;
        while (m>4) {
            m = isHappy(bitSquareSum(n));
        }
        return m==1;
    }
    ///集合
    bool isHappyyy(int n) {
        while (1) {
            n = bitSquareSum(n);
            if (n == 4) {
                return false;
            }
            if (n == 1) {
                return true;
            }
        }
    }
};
