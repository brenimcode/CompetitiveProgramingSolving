#include <bits/stdc++.h>

using namespace std;

// (x^n) % m - Exponenciação Modular Rápida O(log N)
int modpow(int x, int n, int m) {
    // Se o expoente é 0, qualquer número elevado a 0 é 1.
    if (n == 0) return 1 % m;
    
    // Chamada recursiva dividindo o expoente pela metade
    long long u = modpow(x, n / 2, m);
    
    // Combina os resultados das chamadas recursivas
    // Primeiro eleva ao quadrado o resultado da chamada recursiva
    u = (u * u) % m;
    
    // Se o expoente original é ímpar, multiplica por x uma vez mais
    if (n % 2 == 1) u = (u * x) % m;
    
    // Retorna o resultado da exponenciação modular
    return u;
}


int main(){



    
}