//
//  code_3.cpp
//  NodeList
//
//  Created by hapii on 2019/11/29.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <unordered_set>
#include <string>

using namespace std;

/*
 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

 示例 1:

 输入: "abcabcbb"
 输出: 3
 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 */

class code_3{
public:
    int lengthOfLongestSubstring(string s) {
           if (s.size() == 0) {
               return 0;
           }
           unordered_set<char> lookup;///滑动窗口
           int maxStr = 0;
           int left = 0;
        
           for (int i = 0; i<s.size(); i++) {
               /// 遇到重复的一直往后删除，知道没有f重复
               while (lookup.find(s[i]) != lookup.end()) {
                   lookup.erase(s[left]);
                   left++;
               }
               
               maxStr = max(maxStr,i-left+1);
               lookup.insert(s[i]);
           }
           return maxStr;
       }
};
