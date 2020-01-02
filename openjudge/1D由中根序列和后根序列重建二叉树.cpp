#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> pre;

void do_deep(vector<int>& in, vector<int>& post){
    if(post.size() == 0)
        return;
    int root = post[post.size() - 1];
    int root_index = 0;
    pre.push_back(root);
    vector<int> in_left, post_left;
    for(int i = 0; i < in.size(); i++){
        if(in[i] == root){
            root_index = i;
            break;
        }
        in_left.push_back(in[i]);
        post_left.push_back(post[i]);
    }
    do_deep(in_left, post_left);
    vector<int> in_right, post_right;
    for(int i = root_index + 1; i < in.size(); i++){
        in_right.push_back(in[i]);
        post_right.push_back(post[i - 1]);
    }
    do_deep(in_right, post_right);
}

int main(){
    vector<int> v;
    int t;
    while(cin >> t){
        v.push_back(t);
    }
    vector<int> in, post;
    for(int i = 0; i < v.size() / 2; i++){
        in.push_back(v[i]);
        post.push_back(v[i + v.size() / 2]);
    }
    do_deep(in, post);
    for(int i = 0; i < pre.size(); i++){
        cout << pre[i] << " ";
    }
    cout << endl;
}