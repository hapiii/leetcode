//
//  code_739.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/19.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>
/*
 根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。

 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
 */
using namespace std;

class code_739 {
    
public:
    
    vector<int> dailyTemperatures(vector<int>& T) {
        
        vector <int> result (T.size(), 0);
        stack <int> stack;
        for(int i = T.size()-1; i >= 0; --i)
        {///维护最大栈
            while(!stack.empty() && T[i] >= T[stack.top()]){
                 stack.pop();
            }
            if(stack.empty())
                result[i] = 0;
            else
                result[i] = stack.top() - i;
            stack.push(i);
        }
        return result;
    }
    
    
    
   
};
