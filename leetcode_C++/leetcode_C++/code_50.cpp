//
//  code_50.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/24.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//实现 pow(x, n) ，即计算 x 的 n 次幂函数。
class code_50 {
    
private:
    
    double pow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        double half = pow(x, n/2);
        if (n%2 == 0) {
            return half*half;
        }else{
            return half*half*x;
        }
    };

public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1/x;
            N = -N;
        }
        return pow(x, N);
    };
    
    void test() {
           myPow(2, 10);
       }
};
