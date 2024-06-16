#include <bits/stdc++.h> // Importa todas as bibliotecas padrão do C++ de uma vez
using namespace std;

#define NMAX 200100
#define int long long

int bit[NMAX], n;

// atualiza o valor v em v[X]
void upd(int x, int v){
    
    //Itera sobre todos indices "relevantes", o pai do indice i é ( i + lsb(i) )
    // lsb(i) = (x * -x);
    while(x <= n){ 
        bit[x] += v;
        x += (x & -x);
    }
}

// retorna soma de [1,X]
int sum(int x){
    int res = 0;

    // enquanto nao chegar na raiz, faça.
    while(x > 0){ 
        // Res += bit[x], depois, RES += Pai(bit[x]).
        // Navega do Nó(x) à Nó(0). somando apenas naquele RAMO.
        res += bit[x];
        x -= (x&-x);
    }
    return res;
}
// retorna soma [X,Y]
int sum_intervalos(int x,int y){
    return sum(y) - sum(x-1);
}


int main() {


    // Inicializar com zeros a BIT
    for (int i = 0; i <= n+5; i++)
    {
        bit[i] = 0;
    } // Inicializa a BIT com UPD()
    for (int i = 1; i <= n; i++)
    {
        int aux;
        cin >> aux;
        upd(i,aux); // [1,1]
    }
    

    return 0;
}
