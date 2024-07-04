#include <bits/stdc++.h>

using namespace std;
#define int long long
#define NMAX 1100

int n, m;
vector<int> adj[NMAX];
bool visited[NMAX];
vector<int> bases;
vector<int> pilhaRec;


bool estaNaPilha(int v){
    for (int i : pilhaRec)
    {
        if(i == v){
            return true;
        }
    }
    return false;
    
}

void dfs(int i) {
    visited[i] = true;
    for (auto viz : adj[i]) {
        if (!visited[viz]) {
            pilhaRec.push_back(viz);
            dfs(viz);
        }else if(estaNaPilha(viz)){
                // achei um ciclo, adiciono todo o ciclo no bases
                for (int aux : pilhaRec)
                {
                    bases.push_back(aux);
                }
        }
    }
    
}

void topological() {
    fill(visited, visited + NMAX, false); // Inicializa o vetor visited com false
    bases.clear(); // Limpa a ordenação anterior

    for (int i = 1; i <= n; i++) {
        if (!visited[i]){
            dfs(i);
            pilhaRec.push_back(i);
        } 
    }
    reverse(bases.begin(), bases.end()); // Reverte a ordenação para obter a ordem correta
}

int32_t main() {
    while (cin >> n >> m) {
        if(n == 0 && m == 0) break;
        // Limpa o grafo anterior
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
        }

        while (m--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        topological();

        if(bases.empty()){ // se estiver vazio, printe espaço em branoc
            cout << endl << endl;
            continue;
        }

        for (int i = 0; i < (int) bases.size(); i++) {
            cout << " [" << bases[i] << "] ";
        }
        cout << endl;
    }

    return 0;
}