//
//  code_29.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/2/9.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
#include <unordered_set>
#include <limits.h>
using namespace std;
class code_29 {
    
    
public:
    int divide(int dividend, int divisor) {
         //边界情况
               if(dividend == divisor) return 1;
               if(divisor == INT_MIN) return 0;
               
               bool flag = dividend == INT_MIN;
               if(flag) dividend += abs(divisor);
               
               bool same = dividend >= 0 == divisor >= 0;//是否同正负
               dividend = abs(dividend);//全部转化为正数处理
               divisor = abs(divisor);
               
               int res = 0;
               for(int i = 31; i >= 0; i--) {
                   int temp = dividend >> i;
                   res = (res << 1) + (temp >= divisor);
                   if(temp >= divisor) dividend -= divisor << i;
               }
               if(flag) return same ? (res != INT_MAX ? res + 1 : res) : -res - 1;
               return same ? res : -res;
    }
    
    int dividee(int dividend, int divisor) {
           // 特判
           if (divisor == 0) return 0;
           if (divisor == 1) return dividend;
           if (dividend == INT_MIN && divisor == -1) return INT_MAX;
           
           int signdiff = (dividend > 0) ^ (divisor >0);
           
           long t = abs((long)dividend);
           long d = abs((long)divisor);
           int result = 0;
           
           for (int i = 31; i >= 0; i --){
               
               if ((t >> i) >= d){
                   result += 1 << i;
                   t -= d << i;
               }
           }
           return signdiff ? -result : result;
       }
};
