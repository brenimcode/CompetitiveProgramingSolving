#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " = " << x << endl;
#define par pair<int,int> // (custo,vertice)
#define NMAX 505
#define MMAX 124755

vector<par> adj[NMAX]; // {Peso, vizinho}
int n,m;


void addEdge(int u, int v, int cost) {
    adj[u].emplace_back(cost, v);
    adj[v].emplace_back(cost, u);
}


// Algoritmo de PRIM para arvore geradora minima
int primMST(int start) {
    // Fila de prioridade invertida (Menor no topo)

    priority_queue<par, vector<par>, greater<par> > minHeap;
    vector<bool> visited(n, false); // visited
    int totalCost = 0;

    // Iniciar com todas as arestas do vértice inicial
    for(auto it : adj[start]){
        minHeap.push(it);
    }
    visited[start] = true; // acabei de visitar todos vizinhos do vertice inicial

    while(!minHeap.empty()) {
        auto [cost, vertex] = minHeap.top(); // Seleciono a ARESTA com MENOR CUSTO
        minHeap.pop(); // Removo ela.

        if (!visited[vertex]) { // Se ela nao foi visitada, visito.
            visited[vertex] = true; // marco como visitado este vertice.
            totalCost += cost;

            // Adicionar todas as arestas do vértice atual ao heap
            for (const auto &edge : adj[vertex]) {
                if (!visited[edge.second]) {
                    minHeap.push(edge);
                }
            }
        }
    }
    return totalCost;

}


int sum_length() {
    // Soma as arestas e usa PrimMST para auxiliar
    return primMST(1);
}


int32_t main()
{
    cin >> n >> m;

    int u,v,c;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> c;
        // adiciono aresta 
        addEdge(u,v,c);
    }

    cout << sum_length() << endl;

}