/*
    Cadeia alimentar - beecrowd 1903
    author: brenimcode
*/


#include <bits/stdc++.h>
using namespace std;

#define int long long
#define NMAX 1000005
#define DEBUG(x) cout << #x << " == " << (x) << endl

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

    // Transpor o grafo (Trocando a orientacao das arestas)
    for (int v = 1; v <= n; ++v) {
        for (int u : adj[v]) {
            adjT[u].push_back(v);
        }
    }

    // Segunda passada: DFS no grafo transposto na ordem inversa de término
    fill(visited, visited + NMAX, false);
    reverse(order.begin(), order.end());


    for (int i = 0; i < (int) order.size(); ++i) {
    if (!visited[order[i]])
            dfs2(order[i]);
    }


    // Se eu tenho apenas 1 componente fortemente conexa, isso sigfnica que todos vertices de G sao mutuamente alcançaveis.
    return (int) component.size() == 1;
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (isStronglyConnected(n)) {
        cout << "Bolada" << endl;
    } else {
        cout << "Nao Bolada" << endl;
    }

    return 0;
}