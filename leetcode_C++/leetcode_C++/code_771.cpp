//
//  code_771.cpp
//  NodeList
//
//  Created by hapii on 2019/11/29.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;
/*
 给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
 
 J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。
 
 示例 1:
 
 输入: J = "aA", S = "aAAbbbb"
 输出: 3
 */
class code_771 {
public:
    int numJewelsInStones(string J, string S) {
        //1.将宝石存入hash表里
        unordered_map<char, int> jewels;
        for (auto c : J)
            jewels[c] ++;
        
        int sum = 0;
        //2.遍历石头，判断是否是宝石，如果是, 计数加一
        for (auto c : S)
            sum += jewels[c]; // may insert new elements
        return sum;
    }
    
};
