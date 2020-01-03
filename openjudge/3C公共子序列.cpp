#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string a, b;
    while(cin >> a >> b){
        int f[a.size() + 1][b.size() + 1];
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= a.size(); i++){
            for(int j = 1; j <= b.size(); j++){
                if(a[i - 1] == b[j - 1]){
                    f[i][j] = f[i - 1][j - 1] + 1;
                }
                else{
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        cout << f[a.size()][b.size()] << endl;
    }
}