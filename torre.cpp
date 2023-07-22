#include <iostream>
#include <cmath> 
#include <stdlib.h>

using namespace std;

int main(){
    int n,i,j,k,maior = 0,soma=0;
    cin >> n;
    int mat[n][n],linha[n],coluna[n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++){
            cin >> mat[i][j];
        }
        linha[i] = 0;
        coluna[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            linha[i] += mat[i][j];
            coluna[i] +=mat[j][i];
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            soma = (linha[i] + coluna[j]) - (2*mat[i][j]);
            
            if(maior < soma){
                maior = soma;
            }
        }
    }
    cout << maior << endl;

}