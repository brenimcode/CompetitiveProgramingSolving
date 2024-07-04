#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> CicloEuleriano, edges_out[MAXN];
int in_degree[MAXN], out_degree[MAXN];

void AcharCicloEuler(int u) { // Encontra um ciclo euleriano iniciando em qualquer vértice
    while (!edges_out[u].empty()) {
        int v = edges_out[u].back();
        edges_out[u].pop_back();
        AcharCicloEuler(v);
    }
    CicloEuleriano.push_back(u);
}

bool VerificarCicloEuleriano(int N) {
    // Verifica se todos os vértices têm grau de entrada igual ao grau de saída
    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] != out_degree[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    // Exemplo de configuração do grafo
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        edges_out[u].push_back(v);
        out_degree[u]++;
        in_degree[v]++;
    }

    // Verifica se o grafo possui um ciclo euleriano
    if (!VerificarCicloEuleriano(N)) {
        cout << "Não possui Ciclo Euleriano.\n";
    } else {
        // Encontra um ciclo euleriano iniciando em qualquer vértice
        AcharCicloEuler(1); // Supondo que queremos começar do vértice 1

        // Inverte o vetor para obter a ordem correta dos vértices no ciclo euleriano
        reverse(CicloEuleriano.begin(), CicloEuleriano.end());

        // Imprime o ciclo euleriano
        cout << "Ordem dos vértices no Ciclo Euleriano:\n";
        for (int v : CicloEuleriano) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}
