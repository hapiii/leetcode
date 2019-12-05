//
//  main.cpp
//  leetcode_C++
//
//  Created by hapii on 2019/11/29.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <iostream>
#include "code_724.cpp"
#include "code_151.cpp"
#include "code_26.cpp"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> tempArr;
    tempArr.push_back(1);
    tempArr.push_back(1);
    tempArr.push_back(2);
    tempArr.push_back(2);
    tempArr.push_back(3);
    tempArr.push_back(4);
    
    code_724().pivotIndex(tempArr);
    code_151().reverseWords("  hello world!  ");
    
    code_26().removeDuplicates(tempArr);
    return 0;
}
