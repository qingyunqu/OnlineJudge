#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node_t {
    char c;
    node_t* left;
    node_t* right;
};

int id = 0;

node_t* build(vector<string>& tree, int level){
    if(id >= tree.size())
        return NULL;
    string t = tree[id];
    if(t.size() < level)
        return NULL;
    if(t[t.size() - 1] == '*'){
        id++;
        return NULL;
    }
    node_t* node = new node_t;
    node->c = t[t.size() - 1];
    id++;
    node->left = build(tree, level + 1);
    node->right = build(tree, level + 1);
    return node;
}

void preorder(node_t* node){
    if(node == NULL)
        return;
    cout << node->c;
    preorder(node->left);
    preorder(node->right);
}

void inorder(node_t* node){
    if(node == NULL)
        return;
    inorder(node->left);
    cout << node->c;
    inorder(node->right);
}

void postorder(node_t* node){
    if(node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->c;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        vector<string> tree;
        string tmp;
        cin >> tmp;
        while(tmp != "0"){
            tree.push_back(tmp);
            cin >> tmp;
        }
        node_t* root = build(tree, 1);
        preorder(root);
        cout << endl;
        postorder(root);
        cout << endl;
        inorder(root);
        cout << endl;
        cout << endl;
        id = 0;
    }
}