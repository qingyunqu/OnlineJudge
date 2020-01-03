#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node_t {
    int l,r;
    node_t(int _l, int _r){
        l = _l;
        r = _r;
    }
    friend bool operator<(const node_t& a, const node_t& b){
        if(a.l < b.l)
            return true;
        else if(a.l == b.l && a.r <= b.r)
            return true;
        else
            return false;
    }
};

int main(){
    vector<node_t> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        v.push_back(node_t(l, r));
    }
    sort(v.begin(), v.end());

    int begin = v[0].l;
    int end = v[0].r;
    bool flag = true;
    for(int i = 1; i < v.size(); i++){
        if(v[i].l > end){
            flag = false;
            break;
        }
        if(end < v[i].r)
            end = v[i].r;
    }
    if(flag){
        cout << begin << " " << end << endl;
    }
    else{
        cout << "no" << endl;
    }
}