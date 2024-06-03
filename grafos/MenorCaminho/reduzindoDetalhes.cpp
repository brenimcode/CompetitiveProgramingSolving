#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 510; // Número máximo de vértices
int INF = LLONG_MAX;  // Valor grande para representar infinito

int n, m, q;           // Número de cidades, estradas e consultas
int w[MAXN][MAXN];     // Peso das arestas (matriz de adjacência)
int d[MAXN][MAXN];     // Distância entre qualquer par de vértices (matriz de distâncias)

// Função que implementa o algoritmo de Floyd-Warshall
void floyd_warshall() {
    // Inicialmente, a distância de u->v será o peso da sua aresta (se existir)
    // Caso não exista, então seu valor será infinito (um valor bem grande) ou 0 se u = v.
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = w[i][j];

    // Processo principal do algoritmo de Floyd-Warshall
    // Adiciona um vértice intermediário k e tenta atualizar as distâncias mínimas
    for (int k = 1; k <= n; k++) { // Vértice intermediário
        for (int i = 1; i <= n; i++) { // Vértice de origem
            for (int j = 1; j <= n; j++) { // Vértice de destino
                if (d[i][k] < INF && d[k][j] < INF) // Evitar overflow certificando-se de que as distâncias intermediárias não são infinitas
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // Atualiza a distância mínima
            }
        }
    }
}

int32_t main() {
    cin >> n >> m;

    // Inicializando a matriz de pesos com infinito e zeros na diagonal
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                w[i][j] = 0; // Distância de um vértice para ele mesmo é 0
            } else {
                w[i][j] = INF; // Inicialmente, todas as distâncias são infinitas
            }
        }
    }

    // Lendo as estradas e preenchendo a matriz de pesos
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        w[a][b] = w[b][a] = min(w[a][b], c); // Atribui o peso da aresta de a para b e de b para a
    }

    floyd_warshall(); // Chama a função para calcular todas as distâncias mínimas

    // Processando as consultas
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
        {
            printf("[%lld]", d[i][j]);
        }
        printf("\n");
        
    }
    

    return 0;
}
