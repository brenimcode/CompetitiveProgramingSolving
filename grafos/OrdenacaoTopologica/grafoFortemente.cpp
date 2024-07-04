#include <bits/stdc++.h>
using namespace std;

#define int long long
#define NMAX 1000005

vector<int> adj[NMAX]; // Grafo original
vector<int> adjT[NMAX]; // Grafo transposto
bool visited[NMAX];
int n;

void bfs(int start, vector<int> graph[]) {
    fill(visited, visited + NMAX, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : graph[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

bool isStronglyConnected() {
    // Primeiro BFS no grafo original
    bfs(1, adj);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            return false; // Se algum vértice não foi visitado, o grafo não é fortemente conexo
        }
    }

    // Construir o grafo transposto
    for (int v = 1; v <= n; ++v) {
        for (int u : adj[v]) {
            adjT[u].push_back(v);
        }
    }

    // Segundo BFS no grafo transposto
    bfs(1, adjT);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            return false; // Se algum vértice não foi visitado, o grafo não é fortemente conexo
        }
    }
    return true;
}

int32_t main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (isStronglyConnected()) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}
