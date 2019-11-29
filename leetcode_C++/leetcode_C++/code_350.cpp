//
//  code_350.cpp
//  NodeList
//
//  Created by hapii on 2019/11/29.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 给定两个数组，编写一个函数来计算它们的交集。

 示例 1:

 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 输出: [2,2]
 示例 2:

 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 输出: [4,9]
 */
class code_350 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> n1Map;
        vector<int> endDatas;
        ///第一个数组存入hash表中 char:出现次数
        for (int i = 0; i<nums1.size(); i++) {
            n1Map[nums1[i]] += 1;
        }
        ///遍历第二个数组
        for (int i = 0; i<nums2.size(); i++) {
            if (n1Map[nums2[i]]>0) {//如果hash表中存在
                endDatas.push_back(nums2[i]);///添加到输出数组中
                n1Map[nums2[i]] -= 1;///hash value 值-1
            }
        }
        return endDatas;
    }
};
