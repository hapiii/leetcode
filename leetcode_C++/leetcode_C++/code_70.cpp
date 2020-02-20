//
//  code_70.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/2/8.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>

class code_70 {
    
    
public:
    int sum;
    ///递归会超时
    int climbStairs(int n) {
        help(n, 0);
        return sum;
    }
    
    void help(int n, int curSum){
        if (curSum == n) {
            sum++;
            return;
        }
        if (n - curSum == 1) {
            help(n, curSum+1);
        }else{
            help(n, curSum+1);
            help(n, curSum+2);
        }
    }
    /*Fib(n)=Fib(n−1)+Fib(n−2)
     台阶: 1 2 3 4 5
     方法: 1 2 3 5 8
     */
    int climbStairss(int n) {
           if(n<3)
               return n;
           int a=1;
           int b=2;
           int t;
           int i;
           for(i=3;i<=n;i++)
           {
               t=a+b;
               a=b;
               b=t;
           }
           return t;
       }
};
