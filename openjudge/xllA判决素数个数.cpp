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
    vector<int> prime;
    prime.push_back(2);
    for(int i = 3; i < 1000; i += 2){
        bool prime_flag = true;
        for(auto j : prime){
            if(i % j == 0){
                prime_flag = false;
                break;
            }
        }
        if(prime_flag){
            prime.push_back(i);
        }
    }

    int x, y;
    cin >> x >> y;
    int cnt = 0;
    for(int i = min(x, y); i <= max(x, y); i++){
        if(i == 1)
            continue;
        bool prime_flag = true;
        for(auto j : prime){
            if(i == j){
                prime_flag = true;
                break;
            }
            if(i % j == 0){
                prime_flag = false;
                break;
            }
        }
        if(prime_flag)
            cnt++;
    }
    cout << cnt << endl;
}