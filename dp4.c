#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int dp[100][100][100][100];

void LCS4(char* a, char* b, char* c, char* d){
    memset(dp, 0, sizeof(int) * 100 * 100 * 100 * 100);
    for(int i = 1; i <= strlen(a); i++){
        for(int j = 1; j <= strlen(b); j++){
            for(int k = 1; k <= strlen(c); k++){
                for(int m = 1; m <= strlen(d); m++){
                    if(a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1] && c[k - 1] == d[m - 1]){
                        dp[i][j][k][m] = dp[i - 1][j - 1][k - 1][m - 1] + 1;
                        printf("%c", a[i - 1]);
                    }
                    else{
                        dp[i][j][k][m] = MAX(dp[i - 1][j][k][m], dp[i][j - 1][k][m]);
                        dp[i][j][k][m] = MAX(dp[i][j][k][m], dp[i][j][k - 1][m]);
                        dp[i][j][k][m] = MAX(dp[i][j][k][m], dp[i][j][k][m - 1]);
                    }
                }
            }
        }
    }
    printf("\n");
}

int main(){
    char p1[2000] = "4869659312285531556152042444555592243046131500442412131557418355242091176674864471079054668778637824";
    char p2[1000] = "3234834904696322533052680";
    for(int i = 0; i < strlen(p1) - 1; i++){
        for(int j = 0; j < strlen(p2) - 1; j++){
            char* p11 = malloc(strlen(p1) + 1);
            p11[0] = '\0';
            char* p12 = p1 + i + 1;
            strcpy(p11, p1);
            p11[i + 1] = '\0';
            char* p21 = malloc(strlen(p2) + 1);
            p21[0] = '\0';
            char* p22 = p2 + j + 1;
            strcpy(p21, p2);
            p21[j + 1] = '\0';
            LCS4(p11, p12, p21, p22);
        }
    }
}
