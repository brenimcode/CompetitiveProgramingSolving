#include <bits/stdc++.h>

using namespace std;
#define int long long
#define NMAX 10010
#define par pair<int, int> // {PESO,VERTICE}
#define INF 20010

int n,m;
vector <par> vizinhos[NMAX];
int dist[NMAX];
bool processados[NMAX];

int dijkstra(int ori){
    for (int i = 0; i <= n; i++)
    {
        dist[i] = INF;
        processados[i] = false;
    }
    dist[ori] = 0;

    priority_queue< par, vector<par>, greater<par> > fila;

    fila.push({0,ori});

    while(!fila.empty()){
        //pega o topo
        int vAtual = fila.top().second;
        fila.pop();

        // ignora se ja foi processado
        if(processados[vAtual]) continue;
        
        processados[vAtual] = true;

        for (auto viz : vizinhos[vAtual])
        {
            int vViz = viz.second;
            int pViz = viz.first;

            if(dist[vViz] > dist[vAtual] + pViz){
                dist[vViz] = dist[vAtual] + pViz;
                fila.push({dist[vViz], vViz});
            }
        }
    }
     return dist[n-1];

}


int32_t main()
{
    cin >> n >> m;


    int a,b,p;
    while(m--){
        cin >> a >> b >> p;
        vizinhos[a].push_back({p,b});
        vizinhos[b].push_back({p,a});
    }

    int mat[n][n];
    memset(mat,0,sizeof mat);

    for (int i = 0; i < n; i++)
    {
        
    dijkstra(i);

    for (int j = 0; j < n; j++)
    {
        mat[i][j] = dist[j];
        //cout << " ["<< dist[j] <<"] ";
    }

    }

    priority_queue< int, vector<int>, greater<int> > fila;

    for (int i = 0; i < n; i++)
    {
    int maior = mat[0][i];
    for (int j = 0; j < n; j++)
    {
        if(maior < mat[j][i]){
            maior = mat[j][i];
        }
    }
    fila.push(maior);
    }

    cout << fila.top() << endl;



}