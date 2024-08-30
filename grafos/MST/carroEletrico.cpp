#include <bits/stdc++.h>
using namespace std;

#define ponto pair<int,int> // (xi, yi)
#define par pair<int,ponto> // (distancia,vertice)

#define MAXN 1010

vector<pair<double, pair<int,int>>> edges; // Lista de arestas (distancia, (índice do vértice1, índice do vértice2))
ponto pontos[MAXN]; // Array para armazenar os pontos (xi, yi)
int parent[MAXN]; // Vetor de pais para Union-Find
int size[MAXN]; // Vetor de tamanhos para Union-Find
int n, autonomia;

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

// Função para calcular a distância euclidiana entre dois pontos
double distancia(ponto a, ponto b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

// Função principal para o algoritmo de Kruskal
void kruskalMST(int n) {
    double mst_cost = 0; // Custo total da MST

    // Ordenar as arestas pelo custo (distância)
    sort(edges.begin(), edges.end());

    // Inicializar Union-Find
    init(n);

    // Percorrer todas as arestas ordenadas
    for (auto edge : edges) {
        double cost = edge.first;
        int u = edge.second.first;  // Índice do ponto 1
        int v = edge.second.second; // Índice do ponto 2

        // Verificar se u e v pertencem a diferentes componentes
        if (find(u) != find(v)) {
            unite(u, v); // Unir os conjuntos de u e v
            mst_cost += cost; // Adicionar o custo da aresta à MST
        }
    }

    // Contar o número de componentes conexas
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (find(i) == i) {
            components++;
        }
    }

    cout <<  components << endl;
}

int main() {
    cin >> n >> autonomia;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pontos[i] = {a, b};
    }

    // Construir todas as arestas possíveis entre os pontos
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = distancia(pontos[i], pontos[j]);
            if (dist <= autonomia) { // Considerar apenas as arestas dentro da autonomia
                edges.push_back({dist, {i, j}});
            }
        }
    }

    kruskalMST(n);

    return 0;
}
