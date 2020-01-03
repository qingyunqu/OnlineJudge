#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int cnt = 0;

void sort_(int* a, int l, int r){
    if(l == r)
        return;
    int mid = (l + r) / 2;
    sort_(a, l, mid);
    sort_(a, mid + 1, r);

    int i = l;
    int j = mid + 1;
    int temp[r - l + 1];
    int index = 0;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]){
            temp[index] = a[i];
            i++;
            index++;
        }
        else{
            temp[index] = a[j];
            j++;
            index++;
            cnt += mid - i + 1;
        }
    }
    while(i <= mid){
        temp[index] = a[i];
        i++;
        index++;
    }
    while(j <= r){
        temp[index] = a[j];
        j++;
        index++;
    }
    for(int i = 0; i < r - l + 1; i++){
        a[l + i] = temp[i];
    }
}

int main(){
    int n;
    cin >> n;
    while(n != 0){
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort_(a, 0, n - 1);
        cout << cnt << endl;
        cnt = 0;
        cin >> n;
    }
}