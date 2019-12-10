//
//  code_498.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/9.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class code_498 {
    
 /*
  给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

  示例:

  输入:
  [
   [ 1, 2, 3 ],
   [ 4, 5, 6 ],
   [ 7, 8, 9 ]
  ]
输出:  [1,2,4,7,5,3,6,8,9]
  */
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> end;
        int hor;
        int ver;
        while (1) {
            end.push_back(matrix[hor++][ver++]);
            hor = ver ==1?hor:ver;
            
        }
    }
};
