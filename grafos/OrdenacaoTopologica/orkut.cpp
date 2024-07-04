/*
    Orkut OBI 2004 - neps 634
    author: brenimcode
*/


#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 105
#define DEBUG(x) cout << #x << " == " << (x) << endl

vector<int> adj[MAXN];
vector<string> friends;
int indegree[MAXN];
bool visited[MAXN];

vector<string> topologicalSort(int n) {
    vector<string> result;
    queue<int> q;

    // Inicializa fila com os vértices de grau de entrada zero
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(friends[u]);

        for (int v : adj[u]) {
            if (!visited[v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

    // Se o número de vértices na ordenação for igual ao número de amigos, retornamos a ordenação
    if ((int) result.size() == n)
        return result;
    else
        return vector<string>(); // Retorna vetor vazio se não for possível ordenar todos os vértices
}

bool hasCycle(int n) {
    // DFS para detectar ciclo
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            stack<int> s;
            s.push(i);
            while (!s.empty()) {
                int u = s.top();
                s.pop();
                visited[u] = true;
                for (int v : adj[u]) {
                    if (!visited[v])
                        s.push(v);
                    else
                        return true; // Ciclo detectado
                }
            }
        }
    }
    return false; // Não encontrou ciclo
}

int32_t main() {
    int n, caseNum = 1;
    while (cin >> n && n != 0) {
        // Leitura dos nomes dos amigos
        friends.clear();
        for (int i = 0; i < n; ++i) {
            string name;
            cin >> name;
            friends.push_back(name);
            adj[i].clear();
            indegree[i] = 0;
            visited[i] = false;
        }

        // Leitura das exigências
        for (int i = 0; i < n; ++i) {
            string friendName;
            int m;
            cin >> friendName >> m;
            int from = find(friends.begin(), friends.end(), friendName) - friends.begin();
            for (int j = 0; j < m; ++j) {
                string reqName;
                cin >> reqName;
                int to = find(friends.begin(), friends.end(), reqName) - friends.begin();
                adj[to].push_back(from); // Inverte a direção da aresta para modelar a exigência
                indegree[from]++;
            }
        }

        // Verifica se há ciclo no grafo
        if (hasCycle(n)) {
            cout << "Teste " << caseNum++ << endl;
            cout << "impossivel" << endl;
            cout << endl;
        } else {
            // Encontra a ordenação topológica
            vector<string> order = topologicalSort(n);

            if (order.empty()) {
                cout << "Teste " << caseNum++ << endl;
                cout << "impossivel" << endl;
                cout << endl;
            } else {
                cout << "Teste " << caseNum++ << endl;
                for (string name : order) {
                    cout << name << " ";
                }
                cout << endl << endl;
            }
        }
    }
    return 0;
}



