#include <bits/stdc++.h>
using namespace std;

#define par pair<int,int> // (custo,vertice)
#define MAXN 1010

vector<pair<int, par>> edges; // Lista de arestas (custo, (vértice1, vértice2))
int parent[MAXN]; // Vetor de pais para Union-Find
int size[MAXN]; // Vetor de tamanhos para Union-Find

// Função para inicializar Union-Find
void init(int n) {
    for (int i = 0; i < n; ++i) {
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
void kruskalMST(int n) {
    vector<pair<int, par>> mst; // Lista para armazenar a MST resultante
    int mst_cost = 0; // Custo total da MST

    // Ordenar as arestas pelo custo (primeiro elemento da tupla)
    sort(edges.begin(), edges.end());

    // Inicializar Union-Find
    init(n);

    // Percorrer todas as arestas ordenadas
    for (auto edge : edges) {
        int cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        // Verificar se u e v pertencem a diferentes componentes
        if (find(u) != find(v)) {
            unite(u, v); // Unir os conjuntos de u e v
            mst.push_back({cost, {u, v}});
            mst_cost += cost; // Adicionar o custo da aresta à MST
        }
    }

    cout << "Custo total da MST: " << mst_cost << endl;
    
    cout << "Arestas da MST:" << endl;
    for (auto edge : mst) {
        cout << "Custo: " << edge.first << " -> Vértices: " << edge.second.first << ", " << edge.second.second << endl;
    }
}

int main() {
    int n = 4; // Número de vértices no grafo
    edges = {{1, {0, 1}}, {2, {0, 2}}, {3, {1, 2}}, {4, {1, 3}}, {5, {2, 3}}};
    
    kruskalMST(n);

    return 0;
}
