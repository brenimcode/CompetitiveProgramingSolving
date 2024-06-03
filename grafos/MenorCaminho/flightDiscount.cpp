#include <bits/stdc++.h>

using namespace std;

#define int long long
// Definindo uma tupla para armazenar a distância, o vértice e se o cupom foi usado
#define tii tuple<int, int, int>

// Definindo um valor máximo para os vértices e uma constante para o infinito
#define MAXN 100010
#define INF LLONG_MAX

vector<pair<int, int>> adj[MAXN];

// Matriz de distâncias, onde dist[u][0] é a menor distância para u sem usar o cupom
// e dist[u][1] é a menor distância para u já tendo usado o cupom
int dist[MAXN][2];

// Função para executar o algoritmo de Dijkstra modificado
void dijkstra() {
    // Fila de prioridade para o Dijkstra, armazenando (distância, vértice, cupom_usado)
    priority_queue<tii, vector<tii>, greater<tii>> pq;
    pq.push({0, 1, 0});
    dist[1][0] = 0;

    // Loop principal do Dijkstra
    while (!pq.empty()) {
        auto [d, u, cupom_usado] = pq.top(); pq.pop();
        
        // Se a distância atual não é a menor possível, ignore
        if (dist[u][cupom_usado] < d) continue;

        // Para cada vizinho v do vértice u
        for (auto [v, w] : adj[u]) {
            // Atualiza a distância de v sem usar o cupom
            if (dist[v][cupom_usado] > d + w) {
                dist[v][cupom_usado] = d + w;
                pq.push({d + w, v, cupom_usado});
            }
            // Atualiza a distância de v usando o cupom, se ainda não foi usado
            if (cupom_usado == 0 && dist[v][1] > d + w / 2) {
                dist[v][1] = d + w / 2;
                pq.push({d + w / 2, v, 1});
            }
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m; // Lê o número de vértices, arestas

    // Lê as arestas do grafo
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c}); // Adiciona a aresta a->b
        adj[b].push_back({a, c}); // Adiciona a aresta b->a (grafo não direcionado)
    }

    // Inicializa a matriz de distâncias com infinito
    fill(&dist[0][0], &dist[0][0] + sizeof(dist) / sizeof(dist[0][0]), INF);

    // Executa o algoritmo de Dijkstra
    dijkstra();

    // Exibe a menor distancia da cidade 1 para n
    cout << min(dist[n][0], dist[n][1])  << endl;

    return 0;
}
