#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,i,aux,j;
    cin >> n >> m;
    int faixas[n-1],premios[n];
    for (i = 0; i < n-1; i++)
    {   // As faixas de intervalo  A1, A2, A3 (X<A1) (1=<X<A2) (A2=<X<A3) (A3=<X)
        cin >> faixas[i];
    }

    for (i = 0; i < n; i++)
    {   //OS PREMIOS DE CADA FAIXA
        cin >> premios[i];
    }

    for (i = 0; i < m; i++)
    {
        cin >> aux;
        //Um numero X, tal que esse numero está em um intervalo
        int ant=0;
        for (j = 0; j < n; j++)
        {   //verificando intervalo
            if(j == n-1){
                if(ant<=aux){
                    cout << premios[j] << ' ';
                    break;
                }
            }
            if(ant<=aux && aux<faixas[j]){
                //achei o intervalo
                cout << premios[j] << ' ';
                break;
            }
            ant = faixas[j];
        }
        
    }
    
    
    return 0;
}