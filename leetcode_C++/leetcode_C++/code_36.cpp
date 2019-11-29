//
//  code_36.cpp
//  NodeList
//
//  Created by hapii on 2019/11/28.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
 
 数字 1-9 在每一行只能出现一次。
 数字 1-9 在每一列只能出现一次。
 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 
 */

class code_36 {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int R,C;
        if(!(R=board.size()) || !(C=board[0].size())) return false;
        int rows[10][10] = {0};///行的数组
        int cols[10][10] = {0};///列的数组
        int cells[3][3][10] = {0};///3*3的数组
        //循环10*10数组
        for(int i=0;i<R;++i){
            for(int j=0;j<C;++j){
                
                if(board[i][j] == '.') continue;//.则跳过本次循环
                int ch= board[i][j]-'0';//字符串转为数字
                //++rows[i][ch] 数组里的第ch位+1
                //如果大于1，说明存在
                if(++rows[i][ch] > 1 || ++cols[j][ch] > 1 || ++cells[i/3][j/3][ch] > 1) return false;
            }
        }
        return true;
    }
    
};
