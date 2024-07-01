#include <bits/stdc++.h>
using namespace std;

#define par pair<int,int> // (custo,vertice)
#define MAXN 1010

vector<par> adj[MAXN]; // Lista de adjacência global

void addEdge(int u, int v, int cost) {
    adj[u].emplace_back(cost, v);
    adj[v].emplace_back(cost, u);
}

vector<par> primMST(int startVertex) {
    priority_queue<par, vector<par>, greater<par>> minHeap;
    vector<bool> visited(MAXN, false);
    vector<par> mst;
    int totalCost = 0;

    // Iniciar com todas as arestas do vértice inicial
    for (auto edge : adj[startVertex]) {
        minHeap.push(edge);
    }
    visited[startVertex] = true;

    while (!minHeap.empty()) {
        auto [cost, vertex] = minHeap.top(); // Seleciono a ARESTA com MENOR CUSTO
        minHeap.pop(); // Removo ela.

        if (!visited[vertex]) { // Se ela nao foi visitada, visito.
            visited[vertex] = true; // marco como visitado este vertice.
            mst.push_back({cost, vertex}); // Adiciono na MST, aresta CUSTO MINIMO da HEAP
            totalCost += cost;

            // Adicionar todas as arestas do vértice atual ao heap
            for (const auto &edge : adj[vertex]) {
                if (!visited[edge.second]) {
                    minHeap.push(edge);
                }
            }
        }
    }

    cout << "Custo total: " << totalCost << endl;
    return mst;
}

int main() {
    addEdge(0, 1, 1);
    addEdge(0, 2, 2);
    addEdge(1, 2, 3);
    addEdge(1, 3, 4);
    addEdge(2, 3, 5);

    int startVertex = 0;
    vector<par> mst = primMST(startVertex);

    cout << "MST:" << endl;
    for (const auto &edge : mst) {
        cout << "Custo: " << edge.first << " -> Vértice: " << edge.second << endl;
    }

    return 0;
}
