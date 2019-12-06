//
//  code_344.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/6.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

/*
 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

 你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

 示例 1：

 输入：["h","e","l","l","o"]
 输出：["o","l","l","e","h"]
 */
class code_344 {
    
public:
    void reverseString(vector<char>& s) {
        
//        for (int i = 0; i<s.size()-1; i++) {
//            s.insert(s.begin()+i,s[s.size()-1]);
//            s.erase(s.begin()+s.size()-1);
//        }
        
        for (int i = 0,j=s.size()-1; i<j; i++,j--) {
            swap(s[i], s[j]);
        }
        
        for (auto a:s) {
            std::cout<<a;
        }
        
    }
};
