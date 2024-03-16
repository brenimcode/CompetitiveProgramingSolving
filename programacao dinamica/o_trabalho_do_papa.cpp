#include <bits/stdc++.h>

using namespace std;

#define maxn 5000
#define maxv 100

typedef long long ll;

int memo[maxn][maxv];

int main(){
    ll n,i,aux1,aux2,j,maior=0;
    cin >> n; //saque
    pair<ll,ll> caixa[n];
    int tamanho = 0;
    for(i=0;i<n;i++){
        cin >> aux1;
        cin >> aux2;
        if(aux1 > aux2) continue;
        tamanho++;
        caixa[i].first = aux2; // Resistencia
        caixa[i].second = aux1; // Peso atual
    }

    sort(caixa,caixa+tamanho); //ordena em ordem crescente de RESISTENCIA
    //o 1° tem r baixo, ele fica no topo.
    ll peso_total = 0;
    for(i=0;i<tamanho;i++){
        if(peso_total + caixa[i].second <= caixa[i].first){
            maior++;
            peso_total += caixa[i].second;
        } 
    }
    cout << maior << endl;

}