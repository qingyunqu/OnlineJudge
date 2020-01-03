#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long cnt = 0;

void merge(int* array, int l, int mid, int r){
    int temp[r - l + 1];
    int index = 0;
    int i = l;
    int j = mid + 1;
    int id2 = -1;
    while(i <= mid && j <= r){
        if(array[i] <= array[j]){
            temp[index] = array[i];
            index++;
            i++;
        }
        else{
            temp[index] = array[j];
            int t = i;
            if(id2 != -1){ // 优化时间
                t = id2;
            }
            for(; t <= mid; t++){
                if(array[j] * 2 < array[t]){
                    cnt += mid - t + 1;
                    id2 = t;
                    break;
                }
            }
            index++;
            j++;
        }
    }
    while(i <= mid){
        temp[index] = array[i];
        index++;
        i++;
    }
    while(j <= r){
        temp[index] = array[j];
        index++;
        j++;
    }
    for(int i = 0; i < r - l + 1; i++){
        array[l + i] = temp[i];
    }
}

void sort_(int* array, int l, int r){
    if(l == r)
        return;
    int mid = (l + r) / 2;
    sort_(array, l, mid);
    sort_(array, mid + 1, r);
    merge(array, l, mid, r);
}

int main(){
    int n;
    cin >> n;
    while(n != 0){
        cnt = 0;
        int array[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        sort_(array, 0, n - 1);
        printf("%lld\n", cnt);
        cnt = 0;
        scanf("%d", &n);
    }
}