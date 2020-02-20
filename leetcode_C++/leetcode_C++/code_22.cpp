//
//  code_22.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/2/4.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class code_22 {
    
    
public:
    //写法1
    vector<string> result;
    vector<string> generateParenthesiss(int n) {
        gen(0, 0, n,"");
        return result;
    }
    
    void gen(int left,int right,int n, string str){
        if (left == n && right == n) {
            result.push_back(str);
            return;
        }
        if (left < n) gen(left+1, right, n, str+'(');
        if (left>right && right < n) gen(left, right+1, n, str+')');
    }
    
    //写法2
    vector<string> generateParenthesis(int n) {
        generateOneByOne("", n, n);
        return result;
    }
    
    void generateOneByOne(string sublist ,int left,int right) {
        if (left == 0 && right == 0) {
            result.push_back(sublist);
            return;
        }
        if (left > 0) generateOneByOne(sublist + '(', left - 1, right);
        if (right > left) generateOneByOne(sublist+ ')', left , right - 1);
    }
};
