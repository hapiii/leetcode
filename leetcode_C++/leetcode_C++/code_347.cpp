//
//  code_347.cpp
//  NodeList
//
//  Created by hapii on 2019/11/29.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

/*
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
*/

class code_347{
    
public:
    vector<int> topKFrequent(const vector<int> &nums, int k) {
        //1.存入hash表
        unordered_map<int, int> count;
        for (auto num : nums)
            count[num]++;
        //2.排序
        using value_t = pair<int, int>;
        vector<value_t> container(count.begin(), count.end());
        auto comp = [](const value_t &v1, const value_t &v2) {return v1.second < v2.second;};
        make_heap(container.begin(), container.end(), comp);
        //3.取前k个放入结果
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(container.begin()->first);
            pop_heap(container.begin(), container.end() - i, comp);
        }
        return result;
    }
};
