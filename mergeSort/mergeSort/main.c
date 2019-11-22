//
//  main.c
//  mergeSort
//
//  Created by hapii on 2019/11/12.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
#define Len 9

void merge(int a[],int start,int mid,int end){
    int n1 = mid - start +1;
    int n2 = end - mid;
    int left[n1] ,right[n2];
    
    int i,j,k;
    for ( i = 0; i<n1; i++) {
        left[i] = a[start+i];
    }
    for ( j = 0; j<n2; j++) {
        right[j] = a[mid+1+j];
    }
    i = j = 0;
    k = start;
    
    while (i<n1 &&j<n2) {
        if (left[i] < right[j]) {
            a[k++] = left[i++];
        }else{
            a[k++] = right[j++];
        }
    }
    while (i<n1) {
        a[k++] = left[i++];
    }
    while (j<n2) {
        a[k++] = right[j++];
    }
}



/*
 0 ,9
 merge (0,4) (0,2) (0,1) (0,0)
 merge
 */
void merge_sort(int a[],int start,int end){
    int mid;
    if (start<end) {
        mid = (start+end)/2;
       // printf("sort (%d-%d, %d-%d) %d %d %d %d %d %d %d %d %d\n",start, mid, mid+1, end,a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7],a[8]);
        merge_sort(a, start, mid);
        merge_sort(a, mid+1, end);
        merge(a, start, mid, end); // 合并
        printf("merge (%d-%d, %d-%d) to %d %d %d %d %d %d %d %d %d\n",
               start, mid, mid+1, end,a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7],a[8]);
    }
}

int main(int argc, const char * argv[]) {
    int a[Len] = { 9, 8, 7, 6, 5, 4, 3, 2,1 };
    
    merge_sort(a, 0, Len-1);
    for( int i=0;i<Len;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
    
}


