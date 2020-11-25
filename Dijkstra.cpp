#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1 << 25;
const int maxn = 1000;

int mat[maxn][maxn];
int dst[maxn];
int visit[maxn];
int path[maxn]; // path[j]记录从s到j最短路上位于j之前的一个顶点
int n, m;

// 时间复杂度 O(n^2)
// 可使用优先队列进行优化
void dijkstra(int s){
    memset(visit, 0, sizeof(visit));
    for(int i = 0; i < n; i++){
        dst[i] = mat[s][i];
    }
    memset(path, -1, sizeof(path));

    visit[s] = 1;
    int total_visited = 1;
    while(total_visited != n){
        int m = INF;
        int index = -1;
        for(int j = 0; j < n; j++){
            if(!visit[j] && m > dst[j]){
                m = dst[j];
                index = j;
            }
        }
        visit[index] = 1;
        total_visited++;
        for(int j = 0; j < n; j++){
            if(!visit[j] && dst[index] + mat[index][j] < dst[j]){
                dst[j] = dst[index] + mat[index][j];
                path[j] = index;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << dst[i] << " ";
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
    dijkstra(0);
    return 0;
}