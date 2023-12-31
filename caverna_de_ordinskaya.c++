#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,maior,menor,i;
    long long soma = 0;
    cin >> n >> m;
    int vet[n];
    vet[0] = 0;
    for (i = 1; i <=n ; i++)
    {   
        cin >> vet[i];
    }

    for (i = 1; i <=n; i++)
    {
        //Ou o valor do vet[i] == vet[i] ou vai ser MAX ou MIN, vet[i] ou M - vet[i]; e isso sempre comparando ao valor
        maior = max(vet[i],m-vet[i]);
        menor = min(vet[i],m-vet[i]);
        if(menor >= vet[i-1]){
            soma+=menor;
            vet[i] = menor;
        }
        else if(maior >= vet[i-1]){
            soma+=maior;
            vet[i] = maior;
        }
        else{
            soma = -1;
            break;
        }
    }

    cout << soma;
}