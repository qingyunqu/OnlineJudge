#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include <string>

using namespace std;

struct node_t {
    int x;
    int y;
};

bool compare(node_t& a, node_t& b){
    return a.x <= b.x;
}

struct cmp {
    bool operator() (const node_t& a, const node_t& b){
        return a.x < b.x;
    }
};

int main() {
    node_t a[2];
    a[0].x = 1;
    a[0].y = 2;
    a[1].x = 1;
    a[1].y = 3;
    sort(a, a + 2, compare);
    priority_queue<node_t, vector<node_t>, cmp> q;
    map<int, string> m;
    m.insert(pair<int, string>(0, "helloworld"));
    map<int, string>::iterator itr;
    itr = m.find(0);
    printf("%s\n", itr->second.c_str());
    printf("%d %d\n%d %d\n", a[0].x, a[0].y, a[1].x, a[1].y);
}
