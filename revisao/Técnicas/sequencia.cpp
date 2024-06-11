#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int32_t main() {
    _
    int n, l, h;
    cin >> n >> l >> h;  // tamanho do array, l = cota inferior, h = cota superior.
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }

    // Algoritmo Subarray Sum Equals X
    unordered_map<int, int> prefixSomas;
    int somaAtual = 0, contador = 0;
    prefixSomas[0] = 1;  // soma prefixada 0 ocorre 1 vez

    for (int i = 0; i < n; i++) {
        somaAtual += arr[i];  // Adiciona o elemento atual à soma prefixada.
        int remover = somaAtual - x;  // Calcula o valor que precisamos encontrar.
        // Verifica se a soma `somaAtual - x` já ocorreu.
        if (prefixSomas.find(remover) != prefixSomas.end()) {
            contador += prefixSomas[remover];  // Incrementa o contador.
        }
        // Atualiza o mapa com a soma prefixada atual.
        prefixSomas[somaAtual]++;
    }

    cout << contador << endl;  // Imprime o número de subarrays com soma exatamente igual a x.

    return 0;
}
