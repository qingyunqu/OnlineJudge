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
    int K;
    cin >> K;
    while(K--){
        int N;
        cin >> N;
        int array[N];
        for(int i = 0; i < N; i++){
            cin >> array[i];
        }
        int dp[N];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i < N; i++){
            dp[i] = 1;
            for(int k = 0; k < i; k++){
                if(array[i] < array[k]){
                    dp[i] = max(dp[i], dp[k] + 1);
                }
            }
        }
        int maxN = 0;
        for(int i = 1; i < N; i++){
            maxN = max(dp[i], maxN);
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i < N; i++){
            dp[i] = 1;
            for(int k = 0; k < i; k++){
                if(array[i] > array[k]){
                    dp[i] = max(dp[i], dp[k] + 1);
                }
            }
        }
        for(int i = 0; i < N; i++){
            maxN = max(dp[i], maxN);
        }
        cout << maxN << endl;
    }
}