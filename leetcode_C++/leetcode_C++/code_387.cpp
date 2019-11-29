//
//  code_387.cpp
//  NodeList
//
//  Created by hapii on 2019/11/29.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <string>

using namespace std;

/*
 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

 案例:

 s = "leetcode"
 返回 0.

 s = "loveleetcode",
 返回 2.
 */
class code_387{
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashmap;
        //字符串存入hash 中 char:出现次数
        for (auto i:s){
            if (hashmap.count(i)) {
                hashmap[i] += 1;
            }else{
                hashmap[i] = 1;
            }
        }
        ///遍历，输出第一个 值为1的key
        for (int j = 0; j<s.length(); j++) {
            if (hashmap[s[j]] == 1) {
                return j;
            }
        }
        return -1;
    }
};
