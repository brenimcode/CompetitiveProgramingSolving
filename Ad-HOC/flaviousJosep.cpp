/*
beecrowd | 1030
A Lenda de Flavious Josephus
Por Neilor Tonin, URI  Brasil
*/
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl;
#define int long long

// Função recursiva para resolver o problema de Josephus
int josephus(int n, int k) {
    if (n == 1)
        return 1; // Base: apenas uma pessoa, ela sobrevive
    return (josephus(n - 1, k) + k - 1) % n + 1; // Passo recursivo para determinar a posição do sobrevivente
}


int32_t main()
{

    int nc, n, k;

    cin >> nc;
    
    for (int cases = 1; cases <= nc; ++cases) {
        int n, k;
        cin >> n >> k;

        int survivor = josephus(n, k); // Chamada da função Josephus para calcular o sobrevivente
        cout << "Case " << cases << ": " << survivor << endl; // Exibição do resultado
    }

    return 0;
}
