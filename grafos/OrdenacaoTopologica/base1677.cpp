#include <bits/stdc++.h>

using namespace std;
#define int long long
#define NMAX 1100

int n, m;
vector<int> adj[NMAX];
bool visited[NMAX];
int grau[NMAX];
vector<int> grausZero; // grau de entrada do vertiec

void topological() {
    fill(visited, visited + NMAX, false); // Inicializa o vetor visited com false
    int ini = 0;

    while(ini < (int) grausZero.size()){
        int atual = grausZero[ini++];

        for(auto viz : adj[atual]){
            grau[viz]--; // reduzo o grau dele.
            if(!grau[viz]){
                grausZero.push_back(viz); // se o grau dele é zero, ele também deve ser adc na lista
            }
        }
    }

    if((int)grausZero.size() < n){
        //tem ciclo
        
    }
    else{ // nao tem ciclo
        for(int i = 0;i < (int)lista.size();i++) cout << ("%d ", lista[i]);
        printf("\n");
    }

}

int32_t main() {
    while (cin >> n >> m) {
        if(n == 0 && m == 0) break;
        // Limpa o grafo anterior
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            grau[i] = 0;
        }

        while (m--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            grau[b]++; // aumentando o grau de entrada
        }

        for(int i = 1;i <= n;i++) if(grau[i] == 0) grausZero.push_back(i);

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