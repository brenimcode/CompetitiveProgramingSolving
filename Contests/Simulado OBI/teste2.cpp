#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> sequencia(N);
    int prefixo_soma[N+1]; 

    // inicializando com 0 o vetor PREFIXO_SOMA.
    for (int i = 0; i < N+1; i++)
    {
        prefixo_soma[i] = 0;
    }
    

    for (int i = 0; i < N; ++i) {
        cin >> sequencia[i];
        prefixo_soma[i + 1] = prefixo_soma[i] + sequencia[i];
    }


    int contador = 0;    
    // Trecho alterado, deixei apenas 1 for, e adicionei as funções upper_bound, lower_bound
    // para achar a soma = K
    for (int i = 1; i < N + 1; ++i) {
        int resp = upper_bound(prefixo_soma + i, prefixo_soma + N + 1, prefixo_soma[i - 1] + K)
         - lower_bound(prefixo_soma + i, prefixo_soma + N + 1, prefixo_soma[i - 1] + K);
         contador += resp;
    }

    cout << contador << endl;

    return 0;
} 