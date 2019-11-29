//
//  code_349.cpp
//  NodeList
//
//  Created by hapii on 2019/11/29.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

/*
 给定两个数组，编写一个函数来计算它们的交集。

 示例 1:

 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 输出: [2]
 */
class code_349 {
public:
    //set
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        set<int> s;
        for (int i = 0;i<nums1.size();i++){
            
            if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end()) {
                s.insert(nums1[i]);
            }
        }
        result.assign(s.begin(), s.end());
        return result;
    }
    //unordered_set
     vector<int> intersectionn(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> u;
            vector<int> answer;
            for(int i:nums1)
                u.insert(i);
            for(int i:nums2){
                auto a = u.find(i);
                if(a!=u.end()){
                    answer.push_back(i);
                    u.erase(a);//删除该数据
                }
            }
            return answer;
        }

   
};
