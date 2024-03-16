#include <bits/stdc++.h>

using namespace std;

int main(){
    int principal=0,secundaria=0,i,j;
    int mat[3][3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if(i==j){
                principal+=mat[i][j];
            }
            if(i+j == 2){
                secundaria+=mat[i][j];
            }
        }
        
    }
    printf("Diagonal principal: %d\n",principal);
    printf("Diagonal secundaria: %d",secundaria);
    
}   