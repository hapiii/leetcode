//
//  code_151.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/4.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/*
 给定一个字符串，逐个翻转字符串中的每个单词。

 示例 1：

 输入: "the sky is blue"
 输出: "blue is sky the"
 */

class code_151{
public:
    
    string reverseWords(string s) {
        
        vector<string> end;
        string temp = "";
        for (int i = 0; i<s.size(); i++) {
            if (s[i] == ' ' && temp.size() > 0) {
                end.push_back(temp);
                temp = "";
            }else if(i == s.size()-1 && temp.size() > 0 && s[i]!= ' ') {
                temp = temp+s[i];
                end.push_back(temp);
                temp = "";
            }else if(s[i] != ' ') {
                temp = temp+s[i];
            }
        }
        
        for (int i = end.size()-1; i>=0; i--) {
            if ( i == end.size()-1) {
                temp =  end[i];
            }else{
                temp = temp + " " + end[i];
            }
        }
       
        return temp;
    }
};

