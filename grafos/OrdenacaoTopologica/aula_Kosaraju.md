# Algoritmo de Kosaraju

O Algoritmo de Kosaraju é utilizado para encontrar componentes fortemente conectadas (SCCs) em um grafo direcionado.

## Passos do Algoritmo

1. **Primeira DFS**:
   - Realize uma DFS no grafo original para determinar a ordem de término dos vértices.
   - Armazene essa ordem em uma pilha.

2. **Transposição do Grafo**:
   - Transponha (inverta) todas as arestas do grafo.

3. **Segunda DFS**:
   - Realize uma DFS no grafo transposto seguindo a ordem de término armazenada na pilha.
   - Cada árvore de DFS resultante será uma componente fortemente conectada.

## Complexidade

- **Tempo**: O(V + E), onde V é o número de vértices e E é o número de arestas.

## Implementação

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define NMAX 100005

vector<int> adj[NMAX]; // Grafo original
vector<int> adjT[NMAX]; // Grafo transposto
vector<int> order; // Ordem de término dos vértices
bool visited[NMAX];
vector<int> component; // Armazena os vértices de um componente fortemente conectado

// Primeira DFS para armazenar a ordem de término dos vértices
void dfs1(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs1(u);
    }
    order.push_back(v);
}

// Segunda DFS no grafo transposto
void dfs2(int v) {
    visited[v] = true;
    component.push_back(v);
    for (int u : adjT[v]) {
        if (!visited[u])
            dfs2(u);
    }
}

bool isStronglyConnected(int n) {
    // Primeira passada: DFS no grafo original para obter a ordem de término
    fill(visited, visited + NMAX, false);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs1(i);
    }

    // Transpor o grafo
    for (int v = 1; v <= n; ++v) {
        for (int u : adj[v]) {
            adjT[u].push_back(v);
        }
    }

    // Segunda passada: DFS no grafo transposto na ordem inversa de término
    fill(visited, visited + NMAX, false);
    reverse(order.begin(), order.end());
    dfs2(order[0]);

    // Se o tamanho do componente encontrado for igual ao número de vértices, o grafo é fortemente conectado
    return component.size() == n;
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (isStronglyConnected(n)) {
        cout << "O grafo é fortemente conectado." << endl;
    } else {
        cout << "O grafo não é fortemente conectado." << endl;
    }

    return 0;
}
