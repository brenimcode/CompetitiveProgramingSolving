#include<bits/stdc++.h>

using namespace std;

const int maxn = 10100;

int n, saldo[maxn];

struct Tupla {
    int valor, ini, fim;

    // Construtor para inicialização
    Tupla(int v = 0, int i = 0, int f = 0) : valor(v), ini(i), fim(f) {}

    // Sobrecarga do operador <
   bool operator<(const Tupla& other) const {
        if (valor != other.valor) {
            return valor < other.valor;
        }
        return (fim - ini) < (other.fim - other.ini);
    }

    // Sobrecarga do operador >
    bool operator>(const Tupla& other) const {
        if (valor != other.valor) {
            return valor > other.valor;
        }
        return (fim - ini) > (other.fim - other.ini);
    }
};

// Retorna o Inicio e FIM da Max Subset sum
pair<int, int> maxSumset() {
    Tupla best(-1, -1, -1); // Inicializa com valores negativos
    Tupla sum(0, 1, 1);
    for (int i = 1; i <= n; i++) {
        if (sum.valor + saldo[i] >= saldo[i]) {
            sum.valor += saldo[i];
            sum.fim = i;
        } else {
            sum.valor = saldo[i];
            sum.ini = i;
            sum.fim = i;
            
        }
        if (sum > best) {
            best = sum;
        }
    }
    if (best.valor <= 0) {
        return {-1, -1};
    }
    return {best.ini, best.fim};
}



int main() {
    int test = 1;
    saldo[0] = 0;
    while(cin >> n){
        if(!n){
            break;
        }

        int a,b;
        for (int i = 1; i <= n; i++)
        {
            cin >> a >> b;
            saldo[i] = a-b;
        }
        printf("Teste %d\n",test++);
        auto par = maxSumset();
        if(par.first == par.second && par.first == -1){
            printf("nenhum");
        }
        else{
            printf("%d %d",par.first, par.second);
        }
        
        printf("\n\n");
    }
}