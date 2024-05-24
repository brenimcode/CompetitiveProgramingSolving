#include <bits/stdc++.h>

using namespace std;
#define NMAX 2010
#define int long long

int peso[NMAX], valor[NMAX]; // Valores e pesos dos Objetos
int tab[NMAX][NMAX]; //Tabela de DP para salvar os estados
int n;


int knap(int obj, int capacidade){

    if(tab[obj][capacidade] != -1) return tab[obj][capacidade];

    if(obj == n+1 || capacidade == 0) return tab[obj][capacidade] = 0;

    int nao_coloca = knap(obj+1,capacidade);

    if(peso[obj] <= capacidade){ //O objeto cabe na mochila?
        int coloca = valor[obj] + knap(obj+1,capacidade-peso[obj]);

        return tab[obj][capacidade] = max(nao_coloca,coloca);
    }
    
    return tab[obj][capacidade] = nao_coloca; // O objeto nao coube na mochila, logo nao podemos colocar
}

int32_t main()
{
    int p,i,aux1,aux2; // P é a capacidade, N é a qtd de itens
    cin >> p >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> aux1 >> aux2; // aux1 = peso, aux2 = valor
        peso[i] = aux1;
        valor[i] = aux2;
    }
    memset(tab,-1, sizeof tab); //Inicializa com -1

    cout << knap(1,p); //Chamo a knapsack e printo

    return 0;
}
