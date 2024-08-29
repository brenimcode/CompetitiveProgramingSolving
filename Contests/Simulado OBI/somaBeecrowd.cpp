#include <bits/stdc++.h>

using namespace std;

#define MAXN 501000
#define int long long

int v[MAXN], pref[MAXN];

int32_t main() {

    int i,n,k;

    cin >> n >> k; // n = numeros de quadrados, k = Soma desejada
    // Leitura dos elementos do vetor
    for (i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    // Calcula os  ( VETOR de SOMA ACUMULADA )
    pref[1] = v[1];
    for (i = 2; i <= n; i++) {
        pref[i] = pref[i - 1] + v[i];
    }

    int ans = 0; // resposta

    for (i = 1; i <= n; i++) {
        // Calcula o número de subintervalos que têm soma igual a k
        int resp = upper_bound(pref + i, pref + n + 1, pref[i - 1] + k)
         - lower_bound(pref + i, pref + n + 1, pref[i - 1] + k);
        // upper_bound -> retorna posição do 1º elemento do vetor de prefixo que é > QUE pref[i - 1] + k.
        // lower_bound -> retorna posição  a posição do 1º elemento do vetor de prefixo que é >= pref[i - 1] + k
        // isso conta quantos subintervalos começam em i têm soma igual a k.
        
        ans += resp; // Adiciona a resposta ao total
    }

    cout << ans << "\n"; // Imprime a resposta
    return 0;
}
