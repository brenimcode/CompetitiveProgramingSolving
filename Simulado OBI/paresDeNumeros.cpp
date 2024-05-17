#include <bits/stdc++.h> // Inclui todas as bibliotecas padrão do C++

using namespace std;

#define int long long // Define 'long long' como 'int'
#define NMAX 1000 // Tamanho máximo do vetor

int32_t main() { // Função principal
    int i, n, l, f, result = 0, j; // Declaração das variáveis
    
    cin >> n >> l >> f; // Leitura do tamanho do vetor (n) e dos limites (l e f)
    int vet[n]; // Declaração do vetor de tamanho n
    
    // Leitura dos elementos do vetor
    for (i = 0; i < n; i++) {
        cin >> vet[i];        
    }
    
    int sum = 0; // Variável para armazenar a soma temporária de elementos
    
    // Loop para percorrer todos os pares de elementos no vetor
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            sum = vet[i] + vet[j];
            if (sum >= l && sum <= f) { // Verifica se a soma está dentro dos limites
                result++; // Se estiver, incrementa o contador de resultados
            }
        }
    }

    cout << result << endl; // Imprime o resultado
    return 0;
}
