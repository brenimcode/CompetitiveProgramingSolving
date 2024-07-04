#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000005

vector<int> adj[NMAX];      // Grafo original
vector<int> adjT[NMAX];     // Grafo transposto
vector<int> order;          // Ordem de término dos vértices na primeira DFS
bool visited[NMAX];         // Array de visitados
stack<int> stk;             // Pilha para ordem de término da primeira DFS
vector<int> SCC[NMAX];      // Componentes fortemente conectadas

void dfs1(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs1(u);
    }
    stk.push(v);    // Empilhar o vértice após visitar todos os vizinhos
}

void dfs2(int v, int index) {
    visited[v] = true;
    SCC[index].push_back(v);  // Adicionar vértice ao componente atual
    for (int u : adjT[v]) {
        if (!visited[u])
            dfs2(u, index);
    }
}

void kosaraju(int n) {
    // Passo 1: DFS no grafo original para preencher a pilha na ordem de término
    fill(visited, visited + NMAX, false);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs1(i);
    }

    // Passo 2: Inverter as arestas do grafo original para criar o grafo transposto
    for (int v = 1; v <= n; ++v) {
        for (int u : adj[v]) {
            adjT[u].push_back(v);
        }
    }

    // Passo 3: DFS no grafo transposto usando a ordem de término da pilha
    fill(visited, visited + NMAX, false);
    int componentIndex = 0;  // Índice para componentes fortemente conectados
    while (!stk.empty()) {
        int v = stk.top();
        stk.pop();
        
        if (!visited[v]) {
            dfs2(v, componentIndex);
            componentIndex++;
        }
    }

    // Imprimir os componentes fortemente conectados
    cout << "Componentes Fortemente Conectadas:\n";
    for (int i = 0; i < componentIndex; ++i) {
        cout << "Componente " << i + 1 << ": ";
        for (int v : SCC[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    kosaraju(n);

    return 0;
}
