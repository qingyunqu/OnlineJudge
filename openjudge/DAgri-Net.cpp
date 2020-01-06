#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct node_t{
    int a, b;
    int w;
    node_t(int _a, int _b, int _w){
        a = _a;
        b = _b;
        w = _w;
    }
    bool operator<(const node_t& n1) const {
        return w < n1.w;
    }
};

int find(int* fa, int x){
    if(fa[x] == -1)
        return x;
    return (fa[x] = find(fa, fa[x]));
}

void union_(int* fa, int x, int y){
    int fx = find(fa, x);
    int fy = find(fa, y);
    if(fx == fy)
        return;
    else
        fa[fx] = fy;
}

int main(){
    int N;
    while(cin >> N){
        int array[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> array[i][j];
            }
        }
        vector<node_t> edges;
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                edges.push_back(node_t(i, j, array[i][j]));
            }
        }
        sort(edges.begin(), edges.end());
        int fa[N];
        memset(fa, -1, sizeof(fa));
        int sum = 0;
        for(auto e : edges){
            if(find(fa, e.a) != find(fa, e.b)){
                sum += e.w;
                union_(fa, e.a, e.b);
            }
        }
        cout << sum << endl;
    }
}