//
//  code_151.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/12/4.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class code_151{
public:
    
    string reverseWords(string s) {
        
        vector<string> end = {};
        string temp = "";
        for (int i = 0; i<s.size(); i++) {
            if (s[i] == ' ' && temp.size() > 0) {
                end.push_back(temp);
                temp = "";
            }else if(i == s.size()-1 && temp.size() > 0) {
                temp = temp+s[i];
                end.push_back(temp);
                temp = "";
            }else{
                temp = temp+s[i];
                
            }
        }
        
        for (int i = end.size()-1; i>=0; i--) {
            std::cout<<end[i]<<"==="<<"\n";
            if ( i == end.size()-1) {
                temp =  end[i];
            }else{
                temp = temp + " " + end[i];
            }
        }
        std::cout<<temp<<"\n";
        return temp;
    }
};

