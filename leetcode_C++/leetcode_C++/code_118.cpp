//
//  code_118.cpp
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
/*
 在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class code_118 {
        
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> endArr;
        vector<int> tempArr;
        for (int i = 0; i<numRows; i++) {
            for (int j = 0; j<=i; j++) {
                if (j==0 || j ==i) {
                    tempArr.push_back(1);
                }else{
                    tempArr.push_back(endArr[i-1][j-1]+endArr[i-1][j]);
                }
            }
            endArr.push_back(tempArr);
            tempArr.clear();
        }
        
        return endArr;
    }
};
 
