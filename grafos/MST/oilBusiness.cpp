#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define par pair<int,int> // (custo,vertice)
#define MAXN 50010

vector<pair<int, par>> edges; // Lista de arestas (custo, (vértice1, vértice2))
int parent[MAXN]; // Vetor de pais para Union-Find
int size[MAXN]; // Vetor de tamanhos para Union-Find

// Função para inicializar Union-Find
void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1; // Inicialmente, cada conjunto tem tamanho 1
    }
}

// Função para encontrar o representante (raiz) de um conjunto usando compressão de caminho
int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]); // Compressão de caminho
    }
    return parent[u];
}

// Função para unir dois conjuntos usando Union by Size
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v) {
        if (size[root_u] > size[root_v]) {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        } else {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        }
    }
}

// Função principal para o algoritmo de Kruskal
int kruskalMST(int n, int m, long long s, vector<int>& deleted_edges) {
    int max_edges = 0;

    // Ordenar as arestas pelo custo (primeiro elemento da tupla)
    sort(edges.begin(), edges.end());

    // Binary search on the number of edges to delete
    int left = 0, right = m;
    while (left <= right) {
        int mid = (left + right) / 2;
        
        // Initialize Union-Find
        init(n);
        long long total_cost = 0;
        int count_edges = 0;
        deleted_edges.clear();

        // Try to delete mid number of edges
        for (auto edge : edges) {
            int cost = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (count_edges == mid) break; // Stop if already deleted mid edges

            if (find(u) != find(v)) {
                unite(u, v); // Unir os conjuntos de u e v
                total_cost += cost; // Adicionar o custo da aresta à MST
                deleted_edges.push_back(edge.first); // Track deleted edge
                ++count_edges;
            }
        }

        if (count_edges == mid && total_cost <= s) {
            max_edges = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return max_edges;
}

int main() {
    int n, m;
    long long s;
    cin >> n >> m >> s;

    edges.clear();
    for (int i = 0; i < m; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges.push_back({cost, {u, v}});
    }

    vector<int> deleted_edges;
    int max_deleted_edges = kruskalMST(n, m, s, deleted_edges);

    cout << max_deleted_edges << endl;
    if (max_deleted_edges > 0) {
        for (int i = 0; i < max_deleted_edges; ++i) {
            cout << deleted_edges[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
