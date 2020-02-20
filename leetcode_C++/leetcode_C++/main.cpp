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
#include "code_344.cpp"
#include "code_498.cpp"
#include "code_50.cpp"
#include "code_33.cpp"
#include "code_153.cpp"
#include "code_46.cpp"

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
    
    vector<char> tempStrs;
    tempStrs.push_back('h');
    tempStrs.push_back('e');
    tempStrs.push_back('l');
    tempStrs.push_back('o');
//    code_724().pivotIndex(tempArr);
//    code_26().removeDuplicates(tempArr);
//    code_344().reverseString(tempStrs);
//    code_498().test();
//    code_50().test();
//    code_33().test();
    code_46().test();
    return 0;
}
