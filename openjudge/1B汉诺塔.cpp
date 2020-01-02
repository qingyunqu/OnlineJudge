#include <stdio.h>
#include <iostream>

using namespace std;

void move(char a, char b, char c, int n){
    if(n == 1){
        cout << n << ":" << a << "->" << c << endl;
    }
    else{
        move(a, c, b, n - 1);
        cout << n << ":" << a << "->" << c << endl;
        move(b, a, c, n - 1);
    }
}

int main(){
    int n;
    char a, b, c;
    cin >> n >> a >> b >> c;
    move('a', 'b', 'c', n);
}