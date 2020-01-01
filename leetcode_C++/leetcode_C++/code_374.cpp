//
//  code_374.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/1.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>
/*
 我们正在玩一个猜数字游戏。 游戏规则如下：
 我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。
 每次你猜错了，我会告诉你这个数字是大了还是小了。
 你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）：

 -1 : 我的数字比较小
  1 : 我的数字比较大
  0 : 恭喜！你猜对了！
 示例 :

 输入: n = 10, pick = 6
 输出: 6

 */

int guess(int num);
class code_374 {
    
    
public:
    int guessNumber(int n) {
        int left = 1,right = n;
        int center = 0;
        while (left<= right) {
            center = left+(right-left)/2;
            if (guess(center) == 0) {
                return center;
            }else if(guess(center) == -1){
                right = center-1;
            }else{
                left = left+1;
            }
        }
        return center;
    }
};
