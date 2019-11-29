//
//  code_454.cpp
//  NodeList
//
//  Created by hapii on 2019/11/29.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
 
 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。
 
 例如:
 
 输入:
 A = [ 1, 2]
 B = [-2,-1]
 C = [-1, 2]
 D = [ 0, 2]
 
 输出:
 2
 */
class code_454{
    
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> hash;
        //1.A,B所有组合的和出现的次数 存入hash表里
        for (int i = 0; i<A.size(); i++) {
            for (int j = 0; j<B.size(); j++) {
                hash[A[i] + B[j]] += 1;
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i<C.size(); i++) {
            for (int j = 0; j<D.size(); j++) {
                //2.取C,D的组合和的 负数
                int sum = C[i]+D[j];
                //3.去hash表里查找，如果存在 结果数加上hash表里的值
                if (hash[-sum] > 0) {
                    ans += hash[-sum];
                }
            }
        }
        return ans;
    }
    
};
