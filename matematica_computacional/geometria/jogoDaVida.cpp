#include <bits/stdc++.h>
#define MAX 55
using namespace std;

// Função para imprimir o estado atual da matriz
void imprimirMatriz(int N, int mat[MAX][MAX]) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cout << (char)('0' + mat[i][j]);
        }
        cout << "\n";
    }
}

int main() {
    int mat[MAX][MAX] = {}; // Matriz principal do Jogo da Vida
    int N, Q; // Dimensão da matriz e número de passos
    cin >> N >> Q;
    
    // Ler o estado inicial da matriz
    for (int i = 1; i <= N; ++i) {
        string linha;
        cin >> linha;
        for (int j = 1; j <= N; ++j) {
            mat[i][j] = (linha[j - 1] == '1') ? 1 : 0; // Converter '1' ou '0' para inteiro
        }
    }

    // Simular Q passos do Jogo da Vida
    for (int passo = 0; passo < Q; ++passo) {
        int vizinhos[MAX][MAX] = {}; // Matriz auxiliar para contar vizinhos vivos
        
        // Contar vizinhos vivos para cada célula
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                vizinhos[i][j] += mat[i + 1][j];     // Célula abaixo
                vizinhos[i][j] += mat[i - 1][j];     // Célula acima
                vizinhos[i][j] += mat[i][j + 1];     // Célula à direita
                vizinhos[i][j] += mat[i][j - 1];     // Célula à esquerda
                vizinhos[i][j] += mat[i + 1][j + 1]; // Célula diagonal inferior direita
                vizinhos[i][j] += mat[i - 1][j - 1]; // Célula diagonal superior esquerda
                vizinhos[i][j] += mat[i + 1][j - 1]; // Célula diagonal inferior esquerda
                vizinhos[i][j] += mat[i - 1][j + 1]; // Célula diagonal superior direita
            }
        }

        // Atualizar o estado da matriz com base nas regras do Jogo da Vida
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (mat[i][j]) { // Célula viva
                    if (vizinhos[i][j] < 2 || vizinhos[i][j] > 3) {
                        mat[i][j] = 0; // Célula morre por solidão ou superpopulação
                    }
                } else { // Célula morta
                    if (vizinhos[i][j] == 3) {
                        mat[i][j] = 1; // Célula revive por reprodução
                    }
                }
            }
        }
    }

    // Imprimir o estado final da matriz
    imprimirMatriz(N, mat);

    return 0;
}
