#include <iostream>

using namespace std;

int main()
{
    int i, j, N,soma1=0,soma2=0;
    cin >> N;
    int p[N][N],vl[N],vc[N]; //vl soma de linhas / vc soma de colunas
    for (i = 0; i < N; i++)
    {
        vl[i] = 0;
        vc[i] = 0;
    }

    for (i = 0; i < N; i++)  //INSERE E ATRIBUI SOMA DA PRIMEIRA LINHA
    {
        for (j = 0; j < N; j++)
        {
            cin >> p[i][j];
            vl[i] += p[i][j];
            vc[j] += p[i][j];
            if(i == j){
                soma1 = soma1 + p[i][j];
            }
            if(i+j == (N-1)){
                soma2 = soma2 + p[i][j];
            }
        }
    }
    bool verifica=true;
    for (i = 0; i < N-1; i++)
    {
        if(vl[i]!=vl[i+1]){
            verifica = false;
        }
        if(vl[i] != vc[i]){
            verifica = false;
        }
        if(vl[i] != soma1){
            verifica = false;
        }
        if (vl[i] != soma2)
        {
            verifica = false;
        }
        if(vc[i]!=vc[i+1]){
            verifica = false;
        }
        if(soma1 != soma2){
            verifica = false;
        }
    }
        if(verifica){
            cout << soma2;
        }
        else {
            cout << -1;
        }
}
