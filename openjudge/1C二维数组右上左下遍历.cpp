#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int row, col;
    cin >> row >> col;
    int array[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> array[i][j];
        }
    }

    int i = 0, j = 0;
    while(1){
        if(i >= 0 && i < row && j >= 0 && j < col){
            printf("%d\n", array[i][j]);
        }
        if(i == row - 1 && j == col - 1){
            break;
        }
        i++;
        j--;
        if(j == -1){
            int tmp = i;
            i = j;
            j = tmp;
            i++;
        }
    }
}