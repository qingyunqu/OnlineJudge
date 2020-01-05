#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1 << 25;
const int maxn = 1000;

int mat[maxn][maxn];
int dst[maxn][maxn];
int path[maxn][maxn];
int n, m;

//时间复杂度O(n^3)
void floyd(){
    memset(path, -1, sizeof(path));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dst[i][j] = mat[i][j];
            if(i != j && mat[i][j] != INF)
                path[i][j] = i;
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(k == i || k == j)
                    continue;
                if(dst[i][k] + dst[k][j] < dst[i][j]){
                    dst[i][j] = dst[i][k] + dst[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << dst[0][i] << " ";
    }
    cout << endl;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)
                mat[i][j] = 0;
            else
                mat[i][j] = INF;
        }
    }

    int u, v, w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        mat[u][v] = w;
    }
    floyd();
    return 0;
}