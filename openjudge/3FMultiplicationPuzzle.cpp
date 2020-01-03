#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dp[110][110];

int deep(int l, int r, int* array){
    if(dp[l][r] != INT_MAX)
        return dp[l][r];
    for(int i = l + 1; i < r; i++){
        dp[l][r] = min(dp[l][r], array[l] * array[i] * array[r] + deep(l, i, array) + deep(i, r, array));
    }
    return dp[l][r];
}

int main(){
    int n;
    cin >> n;
    int array[n];
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    for(int i = 0; i < 110; i++){
        for(int j = 0; j < 110; j++){
            dp[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < 110 - 1; i++){
        dp[i][i + 1] = 0;
    }
    cout << deep(0, n - 1, array) << endl;
}