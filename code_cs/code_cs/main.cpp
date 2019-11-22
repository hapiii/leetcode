//
//  main.cpp
//  code_cs
//
//  Created by hapii on 2019/11/6.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <string>
class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        
        
        for(int i = 0; i < s.length(); i++)
        {
            if (i>0) {
                std::cout<<"-->"<<s[i-1] <<"--->"<<s[i]<<"-差为--->"<<(int)s[i]-(int)t[i]<<"\n";
                std::cout<<"-->"<<t[i] <<"--->"<<t[i-1]<<"-差为--->"<<(int)s[i-1]-(int)t[i-1]<<"\n";
                
                if ((int)s[i]-(int)t[i] != (int)s[i-1]- (int)t[i-1]) {
                    return false;
                }
            }
            
        }
        
        return true;
    }
    /**
      97 100 100 114
     101 103 103 101
     -4  3    3    2
     */
    
};


int main(int argc, const char * argv[]) {
    
    Solution *s = new Solution;
    bool res = s->isIsomorphic("egge", "adda");
    std::cout<< res;
    return 0;
    
}
