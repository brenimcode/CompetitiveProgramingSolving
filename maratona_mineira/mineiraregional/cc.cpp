#include <bits/stdc++.h>

using namespace std;
#define int long long
#define NMAX 1010
#define par pair<int,int> // {PESO,VERTICE}
#define INF 100100

int n,m;
#define par pair<int,int> // {PESO,VERTICE}
vector<par> vizinhos[NMAX];
int dist[NMAX];
bool visitado[NMAX];

int dijkstra(int origem){
    // inicializando os veteres, Nenhum foi visitado e dist = INF
    for (int i = 0; i <= n; i++)
    {
        dist[i] = INF;
        visitado[i] = false;
    }
    dist[origem] = 0;

    priority_queue< par, vector<par> , greater<par> > fila; // menor PESO no TOPO.
    fila.push({dist[origem], origem}); // coloco-o na fila para ser processado.

    while(!fila.empty()){
        int vAtual = fila.top().second; // pego o vertice com MENOR dist
        fila.pop();

        if(visitado[vAtual]) // se ele ja foi visitado, ignora
            continue;
        visitado[vAtual] = true;
        // para cada vizinho do vertice atual, veja se é melhor manter o caminho até ele,
        // ou se é melhor chegar a esse vertice Vizinho a partir do vAtual.
        for(auto vizinho : vizinhos[vAtual]){ 
            int vVizinho = vizinho.second;
            int pesoVizinho = vizinho.first;

            if(dist[vVizinho] > dist[vAtual] + pesoVizinho){
                dist[vVizinho] = dist[vAtual] + pesoVizinho;
                fila.push({dist[vVizinho], vVizinho});
            }
        }
    }
    return dist[n];
    
}

int32_t main(){
    cin >> n >> m;
    
    int a,b,p;

    while(m--){
        cin >> a >> b >> p; // a -> b, peso = p
        vizinhos[a].push_back({p,b});
        vizinhos[b].push_back({p,a});
    }

    cout << dijkstra(1) << endl;
}