#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int t; // número de casos de teste
    cin >> t;

    while (t--) {
        int m; // número de alunos
        cin >> m;

        vector<int> original(m); // fila original de notas
        vector<int> sorted; // fila ordenada

        // Leitura das notas dos alunos
        for (int i = 0; i < m; i++) {
            cin >> original[i];
        }

        // Copiar a fila original para outra fila para ordenação
        sorted = original;

        // Ordenar em ordem decrescente
        sort(sorted.begin(), sorted.end(), greater<int>());

        // Contar quantos alunos não precisaram trocar de posição
        int unchanged = 0;
        for (int i = 0; i < m; i++) {
            if (original[i] == sorted[i]) {
                unchanged++;
            }
        }

        // Saída: número de alunos que não mudaram de posição
        cout << unchanged << endl;
    }

    return 0;
}
