#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct two{
    int x;
    int y;
    two(int _x, int _y){
        x = _x;
        y = _y;
    }
};

int find(int x, int* fa){
    if(fa[x] == -1){
        return x;
    }
    return (fa[x] = find(fa[x], fa));
}

void union_(int x, int y, int* fa, int* size){
    int rx = find(x, fa);
    int ry = find(y, fa);
    if(rx == ry)
        return;
    if(size[rx] > size[ry]){
        fa[ry] = rx;
        size[rx] += size[ry];
    }
    else{
        fa[rx] = ry;
        size[ry] += size[rx];
    }
}

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        int fa[n];
        int size[n];
        for(int i = 0; i < n; i++){
            fa[i] = -1;
        }
        for(int i = 0; i < n; i++){
            size[i] = 1;
        }
        bool butterfly = true;
        vector<two> diff;
        for(int i = 0; i < m; i++){
            int x, y, flag;
            scanf("%d %d %d", &x, &y, &flag);
            if(flag == 0){
                union_(x, y, fa, size);
            }
            else{
                diff.push_back(two(x, y));
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(fa[i] == -1)
                cnt++;
        }
        if(cnt >= 3){
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i < diff.size(); i++){
            if(find(diff[i].x, fa) == find(diff[i].y, fa)){
                butterfly = false;
                break;
            }
        }
        if(butterfly){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}