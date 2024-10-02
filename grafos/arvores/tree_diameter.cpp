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

    // chamo BFS e retorno o max_dist
    int max_dist_v = BFS(1);

    BFS(max_dist_v);


    int max_dist = 0;
    for (int i = 1; i <= n; i++)
    {
        max_dist = max(max_dist,dist[i]);
    }

    cout << max_dist << endl;
    

}
