//
//  code_278.cpp
//  leetcode_C++
//
//  Created by hapii on 2020/1/3.
//  Copyright © 2020 hapii. All rights reserved.
//

#include <stdio.h>

bool isBadVersion(int version);

class code_278 {
    
public:
    
    int firstBadVersion(int n) {
        
        int low=1;
        int high=n;
        int  mid=low+(high-low)/2;  //mid=(low + high)/2;  重点！！
        while(low < high)
        {
            if(isBadVersion(mid)==false)
                low = mid+1;                   //重点！！
            else
                high = mid;
            mid=low+(high-low)/2;
            
        }
        return low;
    }
};
