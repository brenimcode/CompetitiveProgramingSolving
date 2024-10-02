#include <bits/stdc++.h>
using namespace std;

#define N 200010
#define int long long

vector<int> adj[N];
int dp[N];

int solve(int v, int p) {
    // itero sobre os vizinhos de v
    for(auto x : adj[v]){
        if(x == p){ continue;} // se for o pai, ignoro.
        dp[v] += solve(x,v); // dp[v] armazena a quantidade de descendentes que ele tem. entao somo em todos os filhos
    }
    // '++dp[v]' Para contar o proprio vertice como descendente, para na hora do calculo:
    // dp[v] += solve(x,v); Contar todos os descendentes de v possiveis, e depois na hora de printar, só remover 1.
    return ++dp[v];
}

int32_t main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n ; i++) {
        int u;
        cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }

    for (int i = 0; i < N; i++) dp[i] = 0;
    

    solve(1, 1);

    for(int i = 1;i<=n;i++)
        cout << dp[i]-1 << endl;

    return 0;
}
