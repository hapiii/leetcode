//
//  code_200.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/19.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
/*
 给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

 示例 1:

 输入:
 11110
 11010
 11000
 00000

 输出: 1
 */
class code_200 {

private:
    void dfs(vector<vector<char>> &gird,int y,int x){
        int ny = gird.size();
        int nx = gird[0].size();
        gird[y][x] = '0';
        if (y >= 1 && gird[y-1][x] =='1')  dfs(gird, y-1, x);
        if (y+1 < ny && gird[y+1][x] == '1') dfs(gird, y+1, x);
        if (x >= 1 && gird[y][x-1] == '1') dfs(gird, y, x-1);
        if (x+1 <ny && gird[y][x+1] == '1') dfs(gird, y, x+1);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int ny = grid.size();
        if (ny == 0) {
            return 0;
        }
        int nx = grid[0].size();
        int nums_islands = 0;
        for (int y = 0; y<ny; y++) {
            for (int x = 0; x < nx; x++) {
                if (grid[y][x] == '1') {
                    ++nums_islands;
                    dfs(grid, y, x);
                }
            }
        }
        return nums_islands;
    }
};
