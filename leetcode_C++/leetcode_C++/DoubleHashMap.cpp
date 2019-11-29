//
//  DoubleHashMap.cpp
//  NodeList
//
//  Created by hapii on 2019/11/28.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <vector>
using namespace std;
using std::vector;

const static int N = 20011;
 int hash_key[N],hasn_value[N];

 class ArrHashMap{
    
 public:
    
     const static int N = 20011;
     int hash_key[N],hasn_value[N];
     ArrHashMap(){
         memset(hash_key, -1, sizeof(hash_key));
     }
     
    /*
     双散列
     Hi = (hash(key)+di) mod m
     hash2(x) = N-(x%N)
     di = i*hash2(x)
     m 哈希表长度
     TODO:扩容
     */
     int hash(int key){
         int k = key%N;
         while (hash_key[k] != key && hash_key[k] != -1) {
             k = k*hash2(key);
             if (k == N) {
                 k = 0;
             }
         }
         return k;
     }
     
     int hash2(int key){
         int k = key%N;
         //N是小于TableSize的素
         while (hash_key[k] != key && hash_key[k] != -1) {
             k = N-(key%N);
             if (k == N) {
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
