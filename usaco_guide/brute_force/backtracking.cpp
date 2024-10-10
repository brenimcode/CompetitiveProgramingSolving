#include <bits/stdc++.h>
using namespace std;

const int DIM = 8; // Define a dimensão do tabuleiro (8x8)

vector<vector<bool>> blocked(DIM, vector<bool>(DIM)); // Marcações para posições bloqueadas (onde não é possível colocar uma rainha)
vector<bool> rows_taken(DIM); // Indica se uma linha já possui uma rainha
// Indicadores para as diagonais que vão da parte inferior esquerda para a superior direita
vector<bool> diag1(DIM * 2 - 1);
// Indicadores para as diagonais que vão da parte inferior direita para a superior esquerda
vector<bool> diag2(DIM * 2 - 1);

int valid_num = 0; // Contador de soluções válidas

// Função de busca para posicionar as rainhas
void search_queens(int c = 0) {
    // Se chegamos à coluna 8, significa que conseguimos colocar rainhas em todas as colunas (solução válida)
    if (c == DIM) {
        valid_num++; // Incrementa o contador de soluções válidas
        return;
    }

    // Tenta posicionar uma rainha em cada linha da coluna atual
    for (int r = 0; r < DIM; r++) {
        bool row_open = !rows_taken[r]; // Verifica se a linha está livre
        bool diag_open = !diag1[r + c] && !diag2[r - c + DIM - 1]; // Verifica se as diagonais estão livres

        // Se a posição (r, c) não está bloqueada, e a linha e diagonais estão livres, colocamos uma rainha
        if (!blocked[r][c] && row_open && diag_open) {
            // Marca que a linha e as diagonais estão ocupadas
            rows_taken[r] = diag1[r + c] = diag2[r - c + DIM - 1] = true;
            // Chama recursivamente para tentar colocar a próxima rainha na próxima coluna
            search_queens(c + 1);
            // Após retornar, libera a linha e as diagonais para tentar outra configuração
            rows_taken[r] = diag1[r + c] = diag2[r - c + DIM - 1] = false;
        }
    }
}

int main() {
    // Leitura do tabuleiro
    for (int r = 0; r < DIM; r++) {
        string row;
        cin >> row; // Lê cada linha do tabuleiro
        // Marca as posições bloqueadas (com '*') no tabuleiro
        for (int c = 0; c < DIM; c++) { blocked[r][c] = row[c] == '*'; }
    }

    // Inicia a busca para posicionar as rainhas
    search_queens();

    // Imprime o número total de soluções válidas encontradas
    cout << valid_num << endl;
}
