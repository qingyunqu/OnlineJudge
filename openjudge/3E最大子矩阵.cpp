#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int array[N][N];
    for(int i = 0; i < N; i++){
       for(int j = 0; j < N; j++){
           cin >> array[i][j];
       }
    }

    int max_N = INT_MIN;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            int sum[N];
            memset(sum, 0, sizeof(sum));
            for(int t = i; t <= j; t++){
                for(int k = 0; k < N; k++){
                    sum[k] += array[t][k];
                }
            }
            int dp[N];
            memset(dp, 0, sizeof(dp));
            dp[0] = sum[0];
            for(int k = 1; k < N; k++){
                if(dp[k - 1] >= 0){
                    dp[k] = dp[k - 1] + sum[k];
                }
                else{
                    dp[k] = sum[k];
                }
            }
            for(int k = 0; k < N; k++){
                max_N = max(max_N, dp[k]);
            }
        }
    }
    cout << max_N << endl;
}