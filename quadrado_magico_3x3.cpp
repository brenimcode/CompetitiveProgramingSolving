#include <bits/stdc++.h>

using namespace std;

int main(){
    int principal=0,secundaria=0,i,j,c1,c2,c3,l1,l2,l3;
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
    c1 = mat[0][0] + mat[1][0] + mat[2][0];
    c2 = mat[0][1] + mat[1][1] + mat[2][1];
    c3 = mat[0][2] + mat[1][2] + mat[2][2];

    l1 = mat[0][0] + mat[0][1] + mat[0][2];
    l2 = mat[1][0] + mat[1][1] + mat[1][2];
    l3 = mat[2][0] + mat[2][1] + mat[2][2];
    if(c1 == c2 && c2 == c3 && l1 == c3 && l1 == l2 && l2 == l3 && l3 == principal && principal == secundaria){
        cout << "SIM";
    }
    else{
        cout << "NAO";
    }
    
}   