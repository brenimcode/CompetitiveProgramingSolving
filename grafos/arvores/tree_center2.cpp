#include <bits/stdc++.h>

using namespace std;

#define NMAX 200010
#define int long long

vector<int> grafo[NMAX];
int dist[NMAX];
int parent[NMAX];

int BFS(int x) {
    memset(dist, -1, sizeof(dist));
    memset(parent, -1, sizeof(parent));
    queue<int> fila;
    fila.push(x);
    dist[x] = 0;
    
    int max_dist = 0;
    int v_max = x;

    while (!fila.empty()) {
        int v = fila.front();
        fila.pop();

        for (auto viz : grafo[v]) {
            if (dist[viz] == -1) {
                dist[viz] = dist[v] + 1;
                parent[viz] = v; // Armazena o pai do vértice
                fila.push(viz);
                if (dist[viz] > max_dist) {
                    max_dist = dist[viz];
                    v_max = viz;
                }
            }
        }
    }
    return v_max;
}

vector<int> getPath(int u, int v) {
    vector<int> path;
    while (v != -1) {
        path.push_back(v);
        v = parent[v];
    }
    reverse(path.begin(), path.end());
    return path;
}

int32_t main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    // Passo 1: Encontre um diâmetro qualquer com pontas U e V.
    int u = BFS(1); // Encontra um dos extremos do diâmetro
    int v = BFS(u); // Encontra o outro extremo do diâmetro

    // Passo 2: Obtenha o caminho entre U e V
    vector<int> path = getPath(u, v);

    // Passo 3: Determine o centro
    int center = path[path.size() / 2]; // Para um número ímpar, retorna o centro; para par, o primeiro centro

    cout << center << endl;

    return 0;
}
