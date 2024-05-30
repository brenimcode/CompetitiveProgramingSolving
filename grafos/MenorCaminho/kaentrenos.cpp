#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100

int entrosamento[MAX_N][MAX_N];

int main() {
    int N, M;
    cin >> N >> M;

    // Inicializar a matriz de entrosamento
    memset(entrosamento, 0, sizeof(entrosamento));

    // Ler os pares de músicos e seus níveis de entrosamento
    for (int i = 0; i < M; ++i) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        entrosamento[X-1][Y-1] = Z;
        entrosamento[Y-1][X-1] = Z;
    }

    int max_entrosamento = -1;
    vector<int> melhor_banda(3);

    // Gerar todas as combinações de três músicos
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                // Calcular a soma dos níveis de entrosamento dos três pares possíveis
                int soma_entrosamento = entrosamento[i][j] + entrosamento[i][k] + entrosamento[j][k];

                // Verificar se encontramos uma banda com maior entrosamento
                if (soma_entrosamento > max_entrosamento) {
                    max_entrosamento = soma_entrosamento;
                    melhor_banda = {i+1, j+1, k+1}; // Ajuste para um índice baseado em um
                } else if (soma_entrosamento == max_entrosamento) {
                    // Se o entrosamento é igual, escolhemos a lexicograficamente menor
                    vector<int> nova_banda = {i+1, j+1, k+1};
                    if (nova_banda < melhor_banda) {
                        melhor_banda = nova_banda;
                    }
                }
            }
        }
    }

    // Imprimir a melhor banda
    cout << melhor_banda[0] << " " << melhor_banda[1] << " " << melhor_banda[2] << endl;

    return 0;
}
