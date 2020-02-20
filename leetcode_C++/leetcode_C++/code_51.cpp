//
//  code_51.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/2/7.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class code_51 {
    
public:
    
    unordered_set<int> cols;
    unordered_set<int> pie;
    unordered_set<int> na;
    vector<vector<string>> result;
    
    vector<vector<string>> solveNQueens(int n) {
        if (n < 1) return result;
        vector<string> tmp;
        DFS(n, 0, tmp);
        return result;
    }
    
    void DFS(int n,int row, vector<string> cur_state) {
        if (row >= n) {
            result.push_back(cur_state);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cols.find(col) != cols.end()
                || pie.find( row + col) != pie.end()
                || na.find( col- row) != na.end())
                continue;
            
            cols.insert(col);
            pie.insert(row+col);
            na.insert(col-row);
            cur_state.push_back(to_string(col));
            DFS(n, row+1, cur_state);
            
            cols.erase(col);
            pie.erase(row+col);
            na.erase(col-row);
        }
    }
};
