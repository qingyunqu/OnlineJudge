#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1 << 25;
const int maxn = 1000;

int mat[maxn][maxn];
int dst[maxn];
int inqueue[maxn];
int count_[maxn];
int path[maxn];

int n, m;

bool spfa(int s){
    memset(inqueue, 0, sizeof(inqueue));
    memset(count_, 0, sizeof(count_));
    memset(path, -1, sizeof(path));
    for(int i = 0; i < n; i++){
        dst[i] = INF;
    }
    dst[s] = 0;
    queue<int> q;
    q.push(s);
    inqueue[s] = 1;
    count_[s]++;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        inqueue[u] = 0;
        for(int v = 0; v < n; v++){
            if(dst[u] != INF && dst[u] + mat[u][v] < dst[v]){
                dst[v] = dst[u] + mat[u][v];
                path[v] = u;
                if(!inqueue[v]){
                    q.push(v);
                    inqueue[v] = 1;
                    count_[v]++;
                    if(count_[v] > n){
                        return true;
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << dst[i] << " ";
    }
    cout << endl;
    return false;
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
    if(spfa(0))
        cout << "存在负环" << endl;
    else
        cout << "不存在负环" << endl;
    return 0;
}