//
//  code_242.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/16.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

 示例 1:

 输入: s = "anagram", t = "nagaram"
 输出: true
 */

class Solution {
public:
    ///字符串排序 对比
    bool isAnagram(string s, string t){
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
    
    /* hash 解法
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> sHash;
       
        for (int i = 0; i <s.length(); i++) {
            sHash[s.at(i)]++;
            sHash[t.at(i)]--;
        }
        
        for (auto sm : sHash) {
            if (sm.second != 0) {
                return false;
            }
        }
        return true;
    }
     */
};
