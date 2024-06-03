#include <bits/stdc++.h>

using namespace std;
#define NMAX 110
typedef pair<int,int> par; // {PESO, VERTICE}
#define INF 1e5
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int n,m;

vector<par> adj[NMAX];
bool visitado[NMAX];
int distancia[NMAX]; // Armazena as menores distancias


void dijkstra(int ini){
    for (int i = 0; i <= n+1; i++)
    {
        distancia[i] = INF;
        visitado[i] = false;
    }
    distancia[ini] = 0;
    
    // Cria fila de prioridade para processar as menores distancias primeiro
    priority_queue<par, vector<par>, greater<par> > fila;
    fila.push({0,ini});
    
    while(!fila.empty()){

        par atual = fila.top(); // pego o elemento do TOPO
        fila.pop();

        int vAtual = atual.second;

        if(visitado[vAtual]) continue;
        
        visitado[vAtual] = true;

        for (par vizinho : adj[vAtual])
        {
           int distCalculada = vizinho.first + distancia[vAtual];

            if(distancia[vizinho.second] > distCalculada){
                distancia[vizinho.second] = distCalculada;
                fila.push({distancia[vizinho.second], vizinho.second});
            }

        }
        

    }

}

int main(){
    cin >> n >> m; // lendo N vertices, M arestas

    int u,v,w;
    // Lendo arestas e seus pesos
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});

    }

    dijkstra(1);
    
    
    cout << distancia[n] << endl;


    

    return 0;
}