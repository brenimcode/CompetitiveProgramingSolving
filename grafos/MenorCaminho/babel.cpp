#include <bits/stdc++.h>
using namespace std;

#define int long long
#define NMAX 2000
#define par pair<int, int> // (peso, vertice)
#define INF 9999999

vector<par> adj[NMAX]; // (peso, vertice)

int n, m;
bool visited[NMAX];
int distancia[NMAX];

// Mapeamento de vértices (string) para índices (int)
unordered_map<string, int> vertexIndex;
unordered_map<int, string> indexVertex;

void dijkstra(int start) {
    for (int i = 0; i < n; i++) {
        distancia[i] = INF;
        visited[i] = false;
    }
    distancia[start] = 0;
    visited[start] = false;

    priority_queue<par, vector<par>, greater<par>> minHeap;
    minHeap.push({0, start});

    while (!minHeap.empty()) {
        par vAtual = minHeap.top();
        minHeap.pop();

        // Se já foi visitado, continue
        if (visited[vAtual.second]) continue;

        visited[vAtual.second] = true;

        // Percorre os vizinhos
        for (auto viz : adj[vAtual.second]) {
            int vViz = viz.second;
            int pViz = viz.first;

            if (distancia[vAtual.second] + pViz < distancia[vViz]) {
                distancia[vViz] = distancia[vAtual.second] + pViz;
                minHeap.push({distancia[vViz], vViz});
            }
        }
    }
}

int32_t main() {
    cin >> n >> m; // n = número de vértices, m = número de arestas
    string start, destiny;
    cin.ignore();

    // Leitura dos vértices
    for (int i = 0; i < n; i++) {
        string vertex;
        cin >> vertex;
        vertexIndex[vertex] = i; // Mapeia o vértice para o índice
        indexVertex[i] = vertex; // Mapeia o índice de volta para o vértice
    }

    // Leitura das arestas
    for (int i = 0; i < m; i++) {
        string u, v, weight;
        cin >> u >> v >> weight;
        int weightValue = stoll(weight); // Converte o peso para long long
        int uIndex = vertexIndex[u];
        int vIndex = vertexIndex[v];
        adj[uIndex].push_back({weightValue, vIndex});
        adj[vIndex].push_back({weightValue, uIndex}); // Se o grafo for não dirigido
    }

    cin >> start >> destiny;

    // Executa Dijkstra
    int startIndex = vertexIndex[start];
    dijkstra(startIndex);

    // Exibe a distância para o destino
    int destinyIndex = vertexIndex[destiny];
    cout << distancia[destinyIndex] << endl;

    return 0;
}
