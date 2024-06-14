#include <bits/stdc++.h>

using namespace std;

#define MAX_NOS 1010

bool grafo[MAX_NOS][MAX_NOS];

int main() {
    int numNos, numArestas;

    // Leitura do número de nós e arestas
   scanf("%d %d", &numNos, &numArestas);

    // Inicializa a matriz de adjacência com false
    for (int i = 0; i < numNos; i++) {
        for (int j = 0; j < numNos; j++) {
            grafo[i][j] = false;
        }
    }

    // Leitura das arestas e preenchimento da matriz de adjacência
    for (int i = 0; i < numArestas; i++) {
        int no1, no2;
        cin >> no1 >> no2;
        grafo[no1][no2] = true;
        grafo[no2][no1] = true;
    }
    /*
    1 0 1
    1 0 1
    0 0 1
    */


    int numSugestoes;
    int passeiosPossiveis = 0;

    // Leitura do número de sugestões de passeios
    cin >> numSugestoes;

    for (int i = 0; i < numSugestoes; i++) {
        int numParadas;
        cin >> numParadas;
        vector<int> rota(numParadas);

        // Leitura dos nós do passeio
        for (int j = 0; j < numParadas; j++) {
            cin >> rota[j];
        }

        // Verificação se o passeio é possível
        bool ehPossivel = true;
        for (int j = 0; j < numParadas - 1; j++) {
            if (!grafo[rota[j]][rota[j + 1]]) {
                ehPossivel = false;
                break;
            }
        }

        if (ehPossivel) {
            passeiosPossiveis++;
        }

    }

    // Impressão do número de passeios possíveis
    cout << passeiosPossiveis << endl;

    return 0;
}
