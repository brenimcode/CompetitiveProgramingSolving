#include <bits/stdc++.h>
using namespace std;

#define NMAX 1010

int main() {
    int i,n,m,j;
    cin >> n >> m;
    char matrix[n][m];
    char ini,fim;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 'o'){
                ini = i; fim = j;
            }
        }
    }

    // começa em ini e fim, vou apagando o que eu ja andei, quando achar printa i,j


    /*
        <-  j-- (ESQUERDA)
        -> j++  (DIREITA)

        |
        v i++   (BAIXO)
        ^ i--  (CIMA)

    */
    i = ini, j = fim;
    matrix[i][j] = '.';
    while(true){
        //printf("-- ATUAL[%d %d]--\n\n",i,j);
        if(0 < j && matrix[i][j-1] == 'H'){
            // ENTAO PODE IR PARA ESQUERDA (<-)
            matrix[i][j] = '.'; //agora nao posso voltar mais.
            j--; //desloca
        }
        else if(m-1 > j && matrix[i][j+1] == 'H'){
            // ENTAO PODE IR PARA DIREITA (->)
            matrix[i][j] = '.'; //agora nao posso voltar mais.
            j++; //desloca
        }
        else if(0 < i && matrix[i-1][j] == 'H'){
            // ENTAO PODE IR PARA CIMA (^)
            matrix[i][j] = '.'; //agora nao posso voltar mais.
            i--;
        }
        else if(n-1 > i && matrix[i+1][j] == 'H'){
            // ENTAO PODE IR PARA BAIXO (<-)
            matrix[i][j] = '.'; //agora nao posso voltar mais.
            i++;
        }
        else{
            printf("%d %d\n",i+1,j+1);
            return 0;
        }
    }




    return 0;
}
