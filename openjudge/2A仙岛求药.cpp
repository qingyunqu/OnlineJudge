#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct node_t{
    int x, y;
    int l;
    node_t(int _x, int _y, int _l){
        x = _x; y = _y; l = _l;
    }
};

int main(){
    int m, n;
    cin >> m >> n;
    while(m != 0){
        vector<string> map;
        string t;
        int begin_x, begin_y;
        for(int i = 0; i < m; i++){
            cin >> t;
            map.push_back(t);
            for(int j = 0; j < t.size(); j++){
                if(t[j] == '@'){
                    begin_x = i;
                    begin_y = j;
                }
            }
        }
        int flag[m][n];
        bool find_flag = false;
        memset(flag, 0, sizeof(flag));
        queue<node_t> q;
        q.push(node_t(begin_x, begin_y, 0));
        while(!q.empty()){
            node_t node = q.front();
            q.pop();
            if(map[node.x][node.y] == '*'){
                find_flag = true;
                cout << node.l << endl;
                break;
            }
            flag[node.x][node.y] = 1;
            int x = node.x;
            int y = node.y;
            int l = node.l;
            if(x - 1 >= 0 && map[x-1][y] != '#' && flag[x-1][y] == 0){
                q.push(node_t(x-1, y, l+1));
            }
            if(x + 1 < m && map[x+1][y] != '#' && flag[x+1][y] == 0){
                q.push(node_t(x+1, y, l+1));
            }
            if(y - 1 >= 0 && map[x][y-1] != '#' && flag[x][y-1] == 0){
                q.push(node_t(x, y-1, l+1));
            }
            if(y + 1 < n && map[x][y+1] != '#' && flag[x][y+1] == 0){
                q.push(node_t(x, y+1, l+1));
            }
        }
        if(!find_flag){
            cout << -1 << endl;
        }
        
        cin >> m >> n;
    }
}