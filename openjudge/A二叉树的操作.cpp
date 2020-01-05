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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        int node[n][3];
        int father[n];
        for(int i = 0; i < n; i++){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            node[x][1] = y;
            node[x][2] = z;
            if(y != -1)
                father[y] = x;
            if(z != -1)
                father[z] = x;
        }
        for(int i = 0; i < m; i++){
            int type, x, y;
            scanf("%d", &type);
            if(type == 1){
                scanf("%d%d", &x, &y);
                if(father[x] == father[y]){
                    int fx = father[x];
                    int tmp = node[fx][1];
                    node[fx][1] = node[fx][2];
                    node[fx][2] = tmp;
                }
                else{
                    int fx = father[x];
                    int fy = father[y];
                    if(node[fx][1] == x){
                        node[fx][1] = y;
                    }
                    else{
                        node[fx][2] = y;
                    }
                    if(node[fy][1] == y){
                        node[fy][1] = x;
                    }
                    else{
                        node[fy][2] = x;
                    }
                    father[x] = fy;
                    father[y] = fx;
                }
            }
            else{
                scanf("%d", &x);
                int left = x;
                while(node[left][1] != -1){
                    left = node[left][1];
                }
                printf("%d\n", left);
            }
        }
    }
}