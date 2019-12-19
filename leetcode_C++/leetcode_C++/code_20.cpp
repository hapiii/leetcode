//
//  code_20.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/18.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <stack>
using namespace std;
/*
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

 有效字符串需满足：

 左括号必须用相同类型的右括号闭合。
 左括号必须以正确的顺序闭合。
 注意空字符串可被认为是有效字符串。

 示例 1:

 输入: "()"
 输出: true
 示例 2:

 输入: "()[]{}"
 输出: true
 */
class code_20 {
public:
    bool isValid(string s)
    {
        stack<char> store;
        auto strSize = s.size();
        if(strSize % 2 == 1){
            return false;
        }
        for (auto tmpChar : s)
        {
            switch (tmpChar)
            {
                    //如果是(,[,{,就压入栈中
                case '(':
                case '[':
                case '{':
                    store.push(tmpChar);
                    break;
                case ')':
                   if (store.empty() || store.top() != '(') {
                        return false;
                    }
                    store.pop();
                    break;
                case ']':
                    if (store.empty() || store.top() != '[') {
                        return false;
                    }
                    store.pop();
                    break;
                case '}':
                    if (store.empty() || store.top() != '{') {
                        return false;
                    }
                    store.pop();
                    break;
                default:
                    return false;
                    break;
            }
        }
        return store.empty() ? true:false;
    }
};
