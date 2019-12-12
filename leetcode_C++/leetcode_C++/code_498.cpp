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
    
    void test() {
        vector<vector<int>> matrix;
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;
        v1.push_back(1);
//        v1.push_back(2);
//        v1.push_back(3);
//        v2.push_back(4);
//        v2.push_back(5);
//        v2.push_back(6);
//        v3.push_back(7);
//        v3.push_back(8);
        v3.push_back(9);
        
        matrix.push_back(v1);
       // matrix.push_back(v2);
        matrix.push_back(v3);
        findDiagonalOrder(matrix);
    };
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        vector<int> ends;
        int m = matrix.size();///最大Y
        int n = matrix[0].size();
        
        bool isRise = true;
        for (int i = 0; i<m+n; i++) {
            int pm = isRise?m:n;
            int pn = isRise?n:m;
            
            int x = (i<pm)?i:pm-1;
            int y = i - x;
            while (x>=0 &&y <pn) {
                ends.push_back(isRise?matrix[x][y]:matrix[y][x]);
                x--;
                y++;
            }
            isRise = !isRise;
        }
        return ends;
    }
};
