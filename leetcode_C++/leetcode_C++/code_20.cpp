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
            char popChar = ' ';
            switch (tmpChar)
            {
                    //如果是(,[,{,就压入栈中
                case '(':
                case '[':
                case '{':
                    store.push(tmpChar);
                    break;
                case ')':
                    //注意栈为空的情况
                    if (store.empty())
                    {
                        return false;
                    }
                    popChar = store.top();
                    store.pop();
                    if (popChar != '(')
                    {
                        return false;
                    }
                    break;
                case ']':
                    if (store.empty())
                    {
                        return false;
                    }
                    popChar = store.top();
                    store.pop();
                    if (popChar != '[')
                    {
                        return false;
                    }
                    break;
                case '}':
                    if (store.empty())
                    {
                        return false;
                    }
                    popChar = store.top();
                    store.pop();
                    if (popChar != '{')
                    {
                        return false;
                    }
                    break;
                default:
                    return false;
                    break;
            }
        }
        if (store.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
