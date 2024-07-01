#include <bits/stdc++.h>
using namespace std;

#define par pair<int, int> // (peso, vertice)
#define MAXN 110

int n, m, s, d, t;
vector<par> adj[MAXN]; // Lista de adjacência global
int parent[MAXN], sz[MAXN], dist[MAXN]; // Union-Find e distâncias
// Função de busca com compressão de caminho para Union-Find
int find(int v) {
    return (parent[v] == v) ? v : parent[v] = find(parent[v]);
}

// Função para unir dois conjuntos usando Union by Size
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    parent[b] = a;
}

// Função DFS para calcular a distância (mínimo peso no caminho)
void dfs(int v, int p) {
    for (auto [viz, pes] : adj[v]) {
        if (viz == p) continue;
        dist[viz] = min(dist[v], pes);
        dfs(viz, v);
    }
}

int main() {
    int scenario = 1;
    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;

        // Limpar o grafo para o próximo caso de teste
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            sz[i] = 1;
            adj[i].clear();
        }

        vector<tuple<int, int, int>> edges(m); // Peso, vertice1, vertice2
        for (auto &[c, a, b] : edges) {
            cin >> a >> b >> c;
            --c;
        }

        // Ordena as arestas pelo maior peso
        sort(edges.rbegin(), edges.rend());

        // Construir a Maximum Spanning Tree (MST)
        for (auto [c, a, b] : edges) {
            if (find(a) != find(b)) {
                unite(a, b);
                adj[a].emplace_back(b, c);
                adj[b].emplace_back(a, c);
            }
        }

        cin >> s >> d >> t;

        dist[s] = t;
        dfs(0, 0);

        int minTrips = (t + dist[d] - 1) / dist[d];

        cout << "Scenario #" << scenario++ << endl;
        cout << "Minimum Number of Trips = " << minTrips << endl << endl;
    }
    return 0;
}
