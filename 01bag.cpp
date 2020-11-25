#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    int w[n];
    int v[n];
    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(int) * (n + 1) * (m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(j >= w[i - 1]){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}