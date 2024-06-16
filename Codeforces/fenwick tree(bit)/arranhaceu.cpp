#include <bits/stdc++.h> // Importa todas as bibliotecas padrão do C++ de uma vez
using namespace std;

#define NMAX 200100
#define int long long

vector<int> bit;
int n, q; // n = tam(vet), q = queries

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

// 200 -> 300, 200 - v[i] = 100.

// seta o valor v em v[X], calculo a diferença, por exe: 4 -> 10, a diferença é 6, entao só somar 4+6.
void sets(int x, int v){
    upd(x, v - sum_intervalos(x,x));
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    // Inicializar com zeros a BIT
    bit.assign(n + 1, 0);
     // Inicializa a BIT com UPD()
    for (int i = 1; i <= n; i++)
    {
        int aux;
        cin >> aux;
        upd(i,aux); // [1,1]
    }

    int a,k,p;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> k;
        if(a == 1){
            // INFORMAR [1,K]
            cout  <<sum(k) << endl;
        }
        else{
            cin >> p;
            sets(k,p);
        }
    }
    
}
