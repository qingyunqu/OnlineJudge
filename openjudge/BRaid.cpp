#include <stdio.h>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
    long long x, y;
    int type;
};

bool compare(const Node& a, const Node& b){
    if(a.x >= b.x){
        return true;
    }
    else if(a.x == b.x && a.y >= b.y){
        return true;
    }
    else{
        return false;
    }
}

double distance(Node* a, Node* b){
    return sqrt((double)(a->x - b->x) * (a->x - b->x) + (double)(a->y - b->y) * (a->y - b->y));
}

// 分治法：返回当前的最近距离
double fen(Node* node, int left, int right){
    if(left == right){
        return 2147483647;
    }
    int middle = (left + right) / 2;
    double d1 = fen(node, left, middle);
    double d2 = fen(node, middle + 1, right);
    double d = min(d1, d2); // 子问题的最近距离
    for(int i = left; i <= middle; i++){
        for(int j = middle + 1; j <= right; j++){
            if(abs(node[i].x - node[j].x) > d || abs(node[i].y - node[j].y) > d){
                continue;
            }
            double dis = distance(&node[i], &node[j]);
            if(node[i].type != node[j].type && dis <= d){
                d = dis; // 更新当前最近距离
            }
        }
    }
    return d;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Node node[2 * n];
        for(int i = 0; i < n; i++){
            cin >> node[i].x >> node[i].y;
            node[i].type = 0;
        }
        for(int i = n; i < 2 * n; i++){
            cin >> node[i].x >> node[i].y;
            node[i].type = 1;
        }
        sort(node, node + 2 * n, compare);
        double ans = fen(node, 0, 2 * n - 1);
        printf("%.3lf\n", ans);
    }
}