#include <iostream>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAXN 6

struct products {
    int c, k, price;
};

struct offers {
    int num[MAXN - 1];
    int price;
};

products pro[MAXN - 1];
int b, s;
int dp[MAXN][MAXN][MAXN][MAXN][MAXN];

int dp_(const offers* off, int* k){
    if(dp[k[0]][k[1]][k[2]][k[3]][k[4]] != -1){
        return dp[k[0]][k[1]][k[2]][k[3]][k[4]];
    }

    dp[k[0]][k[1]][k[2]][k[3]][k[4]] = 1e7;
    for(int i = 0; i < b + s; i++){
        bool flag = true;
        for(int j = 0; j < 5; j++){
            if(k[j] < off[i].num[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            int kk[5];
            for(int j = 0; j < 5; j++){
                kk[j] = k[j] - off[i].num[j];
            }
            dp[k[0]][k[1]][k[2]][k[3]][k[4]] = min(dp[k[0]][k[1]][k[2]][k[3]][k[4]], off[i].price + dp_(off, kk));
        }
    }
    return dp[k[0]][k[1]][k[2]][k[3]][k[4]];
}

int main(){
    map<int, int> map_produ_i;
    cin >> b;
    memset(pro, 0, sizeof(pro));
    for(int i = 0; i < b; i++){
        cin >> pro[i].c >> pro[i].k >> pro[i].price;
        map_produ_i[pro[i].c] = i;
    }
    cin >> s;
    offers off[b + s];
    memset(off, 0, sizeof(off));
    for(int i = 0; i < b; i++){
        off[i].num[i] = 1;
        off[i].price = pro[i].price;
    }
    for(int i = b; i < b + s; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            int t1, t2;
            cin >> t1 >> t2;
            off[i].num[map_produ_i[t1]] = t2;
        }
        int p;
        cin >> p;
        off[i].price = p;
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0][0] = 0;
    int k[5];
    for(int i = 0; i < 5; i++){
        k[i] = pro[i].k;
    }
    cout << dp_(off, k) << endl;
    return 0;
}
