#include <iostream>

using namespace std;

// Função para calcular a potência de 'base' elevada a 'expoente' módulo 'mod'
long long mod_pow(long long base, long long expoente, long long mod) {
    long long resultado = 1;
    base %= mod;
    while (expoente > 0) {
        if (expoente & 1) {
            resultado = (resultado * base) % mod;
        }
        base = (base * base) % mod;
        expoente >>= 1;
    }
    return resultado;
}

// Função para calcular o inverso modular de 'a' módulo 'm'
long long inverso_modular(long long a, long long m) {
    // Se 'm' não for primo ou 'a' for divisível por 'm', o inverso não existe
    if (m == 1 || m == 0 || a % m == 0) {
        return -1;
    }
    // O inverso modular de 'a' módulo 'm' é 'a^(m-2) % m'
    return mod_pow(a, m - 2, m);
}

int main() {
    long long a, m;
    cin >> a >> m;

    long long inverso = inverso_modular(a, m);
    cout << inverso << endl;

    return 0;
}
