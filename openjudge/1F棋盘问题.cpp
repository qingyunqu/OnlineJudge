#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, k;
int cnt = 0;

bool occupied(int x, int y, vector<int>& ret){
    for(int i = 0; i < ret.size(); i++){
        if(ret[i] / n == x || ret[i] % n == y){
            return true;
        }
    }
    return false;
}

void backtrace(vector<string>& map, int x, vector<int>& ret){
    if(ret.size() == k){
        cnt++;
        return;
    }
    for(int t = x; t < n * n; t++){
        int i = t / n;
        int j = t % n;
        if(map[i][j] == '#' && !occupied(i, j, ret)){
            vector<int> result(ret);
            result.push_back(t);
            backtrace(map, t + 1, result);
        }
    }
}

int main(){
    cin >> n >> k;
    while(n != -1){
        vector<string> map;
        string t;
        for(int i = 0; i < n; i++){
            cin >> t;
            map.push_back(t);
        }
        vector<int> result;
        backtrace(map, 0, result);
        cout << cnt << endl;
        cin >> n >> k;
        cnt = 0;
    }
    
}