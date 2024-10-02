#include <bits/stdc++.h>
using namespace std;

#define N 100010

vector<int> adj[N];
long double ans[N]; // Vetor que armazenará os valores esperados de cada cidade

void dfs(int u, int parent) {
    int child_count = 0;  // Conta o número de filhos de u
    double sum = 0;       // Soma dos valores esperados dos filhos

    // Percorre os vizinhos de u
    for (int v : adj[u]) {
        if (v != parent) {  // Ignora o pai de u
            dfs(v, u);
            sum += ans[v] + 1;  // Soma o valor esperado do filho mais 1 (custo da estrada)
            child_count++;
        }
    }

    if (child_count > 0) {
        ans[u] = sum / child_count;  // Média dos valores esperados dos filhos
    } else {
        ans[u] = 0;  // Se for uma folha, o valor esperado é 0
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS a partir de 1 (raiz)
    dfs(1, -1);

    cout << fixed << setprecision(10) << ans[1] << endl;

    return 0;
}
