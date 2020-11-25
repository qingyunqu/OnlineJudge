#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int price[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &price[i]);
        }

        int left[n], right[n];
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));

        int mmin = price[0];
        for(int i = 1; i < n; i++){ // left[0] = 0;
            left[i] = max(left[i - 1], price[i] - mmin);
            mmin = min(mmin, price[i]);
        }

        int mmax = price[n - 1];
        for(int i = n - 2; i >= 0; i--){ // right[n - 1] = 0;
            right[i] = max(right[i + 1], mmax - price[i]);
            mmax = max(mmax, price[i]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, left[i] + right[i]);
        }
        cout << ans << endl;
    }
}
