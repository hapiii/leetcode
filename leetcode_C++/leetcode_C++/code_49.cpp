//
//  code_49.cpp
//  NodeList
//
//  Created by hapii on 2019/11/28.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 
 示例:
 
 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
 输出:
 [
 ["ate","eat","tea"],
 ["nat","tan"],
 ["bat"]
 ]
 */
class code_49 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> end;
        unordered_map <string,int> hash;
        //1.遍历字符串数组
        for (int i = 0; i<strs.size(); i++) {
            //2.取出字符串并对其排序
            string s = strs[i];
            sort(s.begin(), s.end());
            
            if (hash.count(s)) {
                end[hash[s]].push_back(strs[i]);//如果hash表里已存在，追加原字符串
                
            }else{
                end.push_back(vector<string>());//end 追加字符串数组
                end.back().push_back(strs[i]);//最后一个也就是刚创建的 添加 字符串
                hash[s] = end.size()-1; ///hash s:end.size-1
            }
        }
        return end;
    };
};
