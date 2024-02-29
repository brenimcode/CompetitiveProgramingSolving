#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <bool> e_composto(2150000,false);

void crivo(ll n)
{
    ll i,j;
    e_composto[1] = 1; // o vetor guarda NAO primo. [0] - PRIMO, [1] - !PRIMO
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

int main()
{

    ll n,kk=1,i=2,j;
    cin >> n;
    crivo(n/2);
    printf("KKjK\n");
    vector<ll> e_primo;
    ll fim_vetor = n/2;
    printf("KKjK\n");
    for(i = 2; i<=fim_vetor; i+=kk){
        if(i==3) kk=2;
        if(!e_composto[i])
            if(n%i == 0)
                printf("[%lld] - KKjK\n",i);
                e_primo.push_back(i);
    }
    printf("KKK\n");
    fim_vetor = e_primo.size();

    for(i = 0; i<fim_vetor; i++){
        if(e_primo[i]*e_primo[fim_vetor-1] > n){
            fim_vetor--;
        } // se o meu i * o ultimo numero
            for(j=fim_vetor-1;j>=i ; j--){
                    if(e_primo[i]*e_primo[j] == n){
                        printf("1\n");
                        return 0;
                    }
                }
        }

    printf("0\n");
    return 0;
}
