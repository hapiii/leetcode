//
//  ArrHashMap.cpp
//  NodeList
//
//  Created by hapii on 2019/11/27.
//  Copyright © 2019 hapii. All rights reserved.
//  开放定值法

#include <stdio.h>
#include <stdio.h>
#include <vector>


using namespace std;
using std::vector;

class ArrHashMap{
    
public:
    
    
    const static int N = 20011;
    int hash_key[N],hasn_value[N];
    ArrHashMap(){
        memset(hash_key, -1, sizeof(hash_key));
    }
    int hash(int key){
        /*
         线性探测法
         Hi = (hash(key)+di) mod m
         hash(key) key的hash值
         di 增量序列 1，2...m-1
         m 哈希表长度
         */
        int k = key%N;
        while (hash_key[k] != key && hash_key[k] != -1) {
            if (++k == N) {
                k = 0;
            }
        }
        return k;
    }
    
    void put (int key,int value){
        int k = hash(key);
        hasn_value[k] = value;
        hash_key[k] = key;
    }
    
    int get (int key){
        int k = hash(key);
        if (hash_key[k] != -1) {
            return hasn_value[k];
        }
        return -1;
    }
    void remove (int key){
        int k = hash(key);
        if (hash_key[k] != -1) {
            hasn_value[k] = -1;
        }
        
    }
};

