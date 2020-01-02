#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int N, NA, NB;
    cin >> N >> NA >> NB;
    int a[NA];
    int b[NB];
    for(int i = 0; i < NA; i++){
        cin >> a[i];
    }
    for(int i = 0; i < NB; i++){
        cin >> b[i];
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        int na = a[i % NA];
        int nb = b[i % NB];
        if(na == nb){
            continue;
        }
        else if((na == 0 && nb == 2) || (na == 2 && nb == 5) || (na == 5 && nb == 0)){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    if(cnt == 0){
        cout << "draw" << endl;
    }
    else if(cnt > 0){
        cout << "A" << endl;
    }
    else{
        cout << "B" << endl;
    }
    return 0;
}
