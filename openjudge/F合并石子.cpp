#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//CCF压缩编码问题
//优化：GarsiaWachs算法

int dp[110][110];

int deep(int l, int r, int* array, int* sum){
    if(l == r)
        return 0;
    if(dp[l][r] != INT_MAX)
        return dp[l][r];
    for(int k = l; k < r; k++){
        dp[l][r] = min(dp[l][r], deep(l, k, array, sum) + deep(k+1, r, array, sum) + sum[r+1] - sum[l]);// sum[r] - sum[l - 1]
    }
    return dp[l][r];
}

int main(){
    int n;
    cin >> n;
    int array[n];
    int sum[n + 1];
    memset(sum, 0, sizeof(sum));
    for(int i = 0; i < n; i++){
        cin >> array[i];
        sum[i + 1] = sum[i] + array[i];
    }
    for(int i = 0; i < 110; i++){
        for(int j = 0; j < 110; j++){
            dp[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < n; i++){
        dp[i][i] = array[i];
    }
    cout << deep(0, n - 1, array, sum) << endl;
}