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

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> arr;
    //[1,7,3,6,5,6]
//    arr.push_back(1);
//    arr.push_back(7);
//    arr.push_back(3);
//    arr.push_back(6);
//    arr.push_back(5);
//    arr.push_back(6);
    
    code_724().pivotIndex(arr);
    code_151().reverseWords("  hello world!  ");
    return 0;
}
