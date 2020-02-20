//
//  code_46.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/2/8.
//  Copyright © 2020 hapii. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
class code_46 {
    
    
public:
    void test(){
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        permute(v1);

    }
    
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> res;
       vector<int >path;
       vector<bool> used;
        used.resize(nums.size());
        int len = nums.size();
        if (len == 0) {
            return res;
        }
        DFS(nums, len, 0, path, used, res);
       
        return res;
    }
    
    void DFS(vector<int>& nums,int len,int depth,vector<int> path,vector<bool> used,vector<vector<int>> res){
        if (depth == len) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < len; i++) {
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                DFS(nums, len, depth+1, path, used, res);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};
