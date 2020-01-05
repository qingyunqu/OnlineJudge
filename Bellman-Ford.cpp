#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1 << 25;
const int maxn = 1000;

struct Edge{
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w){}
};

int mat[maxn][maxn];
int dst[maxn];
int path[maxn];
int n, m;

// 先迭代 n-1 次，如果第n次还在更新，说明存在负环
//时间复杂度O(nm)
bool bellmanford(int s){
    vector<Edge> edges;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] != 0 && mat[i][j] != INF){
                edges.push_back(Edge(i, j, mat[i][j]));
            }
        }
    }
    for(int i = 0; i < n; i++){
        dst[i] = INF;
        path[i] = -1;
    }
    dst[s] = 0;

    for(int t = 0; t < n; t++){ // n次
        bool update = false;
        for(auto e : edges){
            int u = e.u;
            int v = e.v;
            int w = e.w;
            if(dst[u] != INF && dst[u] + w < dst[v]){
                dst[v] = dst[u] + w;
                path[v] = u;
                update = true;
                if(t == n - 1)
                    return true; // 存在负环
            }
        }
        if(!update)
            break;
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
    if(bellmanford(0))
        cout << "存在负环" << endl;
    else
        cout << "不存在负环" << endl;
    return 0;
}