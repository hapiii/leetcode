//
//  code_119.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/29.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
/*杨辉三角2

 
 输入: 3
 输出: [1,3,3,1]
 */
class code_119 {
    
    vector<int> lastRows;
    vector<int> endRows;
    
public:
    
    vector<int> helper(int rowIndex,int numRow){
        if (rowIndex == numRow+1) {
            return lastRows;
        }
        for (int i = 0; i<= rowIndex; i++) {
            if (i == 0 || i == rowIndex) {
                endRows.push_back(1);
            }else{
                endRows.push_back(lastRows[i-1]+lastRows[i]);
            }
        }
        lastRows = endRows;
        endRows.clear();
        return helper(rowIndex+1, numRow);
    }
    vector<int> getRoww(int rowIndex) {
        return helper(0,rowIndex);
    }
    ///更加高效的办法，只维护一组数据，每次从后往前加
    vector<int> getRow(int rowIndex) {
        vector<int> results;
        for (int i = 0; i<= rowIndex; i++) {
            results.push_back(1);
            for (int j = i-1; j>0; j--) {
                results[j] += results[j-1];
            }
        }
        return results;
    }
    
    
};
