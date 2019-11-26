//
//  main.cpp
//  NodeList
//
//  Created by hapii on 2019/11/7.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <iostream>
#include "ListNode.cpp"
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
using std::vector;


class Solution {
public:
    #pragma mark === 数组的交集
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        set<int> s;
        for (int i = 0;i<nums1.size();i++){
            
            if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end()) {
                s.insert(nums1[i]);
            }
        }
        result.assign(s.begin(), s.end());
        return result;
    }
#pragma mark === 是否快乐数
    int bitSquareSum(int n){
        int sum = 0;
        while (n>0) {
            int bit = n%10;
            sum += bit*bit;
            n = n/10;
        }
        return sum;
    }
    ///快慢指针
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        } while (slow!= fast);
        
        return slow == 1;
    }
    ///递归解法
    bool isHappyy(int n) {
        int m = n;
        while (m>4) {
            m = isHappy(bitSquareSum(n));
        }
        return m==1;
    }
    ///集合
    bool isHappyyy(int n) {
        while (1) {
            n = bitSquareSum(n);
            if (n == 4) {
                return false;
            }
            if (n == 1) {
                return true;
            }
        }
    }
#pragma mark ===== 387. 字符串中的第一个唯一字符
    int firstUniqChar(string s) {
        unordered_map<char, int> hashmap;
        for (auto i:s){
            if (hashmap.count(i)) {
                hashmap[i] += 1;
            }else{
                hashmap[i] = 1;
            }
        }
        
        for (int j = 0; j<s.length(); j++) {
            if (hashmap[s[j]] == 1) {
                return j;
            }
        }
        return -1;
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    MyLinkedList *list = new MyLinkedList();
    
    ListNode *head = list->addAtTail(1);
    list->addAtTail(2);
    list->addAtTail(3);

    list->removeElements(head, 3);
    list->printList(head);
    
    Solution *s = new Solution();
    bool ok = s->isHappyy(19);
    std::cout<<ok;
    return 0;
}
