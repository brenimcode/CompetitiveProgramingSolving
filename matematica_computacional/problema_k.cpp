#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <bool> e_composto(2147483648,false);

void crivo(ll n)
{
    ll i,j;
    e_composto[1] = 1; // o vetor guarda NAO primo. [0] é PRIMO, [1] - nao é PRIMO
    for ( i = 2; i*i <= n; ++i)
    {
        if (!e_composto[i])
        {
            for ( j = 2; j * i <= n; ++j)
            {
                e_composto[i * j] = 1;
            }
        }
    }
}

bool verifica_primo(int x,bool calcula_novamente){
    if(calcula_novamente) crivo(x);
    if(!e_composto[x-2])
            return true;
}

int main()
{

    ll n,kk=1,i,j,aux,maior;
    cin >> n;
    bool ver=0;
    maior = 4;
    for(i = 0; i<n; i++){
        cin >> aux;
        if(maior < aux){
            maior = aux;
            ver = 1;
        }

        if(aux%2==0){printf("1\n");continue;}
        if(verifica_primo(aux-2,ver)) {printf("1\n");continue;}
        printf("0\n");
        ver = 0;

    }
    printf("0\n");
    return 0;
}
