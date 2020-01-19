//
//  code_75.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/19.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
/*
 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

 注意:
 不能使用代码库中的排序函数来解决这道题。

 示例:

 输入: [2,0,2,1,1,0]
 输出: [0,0,1,1,2,2]
 */
class code_75 {
    
    
public:
   void sortColors(vector<int>& nums) {
       
        int p0 = 0, curr = 0;
       
        int p2 = nums.size() - 1;

        while (curr <= p2) {
          if (nums[curr] == 0) {
            swap(nums[curr++], nums[p0++]);
          }
          else if (nums[curr] == 2) {
            swap(nums[curr], nums[p2--]);
          }
          else curr++;
        }
      }

};
