#include <bits/stdc++.h>

using namespace std;

#define NMAX 200010
#define int long long

vector<int> grafo[NMAX];
int dist[NMAX];

int BFS(int x)
{
    memset(dist, -1, sizeof dist);
    queue<int> fila;
    fila.push(x);
    dist[x] = 0;
    int max_dist = 0;
    int v_max = 1;

    while (!fila.empty())
    {
        int v = fila.front();
        fila.pop();

        for (auto viz : grafo[v])
        {
            if (dist[viz] == -1)
            {
                dist[viz] = dist[v] + 1;
                if(max_dist < dist[viz]){
                    max_dist = dist[viz];
                    v_max = viz;
                }
                fila.push(viz);
            }
        }
    }
    return v_max;
}

int32_t main()
{

    int n;
    cin >> n;
    for (int i = 1; i <= n-1; i++)
    {
        int u,v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    // Passo 1: Encontre um diâmetro qualquer com pontas U e V.
    int u = BFS(1);
    int v = BFS(u);
    // Passo 2: Encontre C no caminho de (U -> V) tal que max(dist(C,U),dist(C,V)) possui o menor valor possível.
    
    int ans = 999999999;
    for (int i = 1; i <= n-1; i++){
        BFS(i);
        ans = min(ans,max(dist[u],dist[v]));
    }

    cout << ans << endl;
    
}
