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
    int M, N;
    cin >> M >> N;
    int w[N], v[N];
    for(int i = 0; i < N; i++){
        cin >> w[i] >> v[i];
    }
    int dp[N + 1][M + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if(j >= w[i - 1]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }
    cout << dp[N][M] << endl;
}