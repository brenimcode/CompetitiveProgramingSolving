#include <bits/stdc++.h>

using namespace std;
#define MAXN 1010
#define pp pair<int, int>
#define INF 2000

int n, m;   // n vertices, m arestas

int distancia[MAXN];  // o array de distâncias à fonte
int processado[MAXN]; // o array que guarda se um vértice foi processado

vector<pp> adjascente[MAXN];

int matriz[MAXN][MAXN];

void dijkstra(int S)
{
    for(int i = 0; i <= n+1; i++) distancia[i] = INF; // Definindo todas distancias como INFINITO, inicialmente
        distancia[S] = 0;       // distancia da ORIGEM -> ORIGEM é 0.

    priority_queue<pp, vector<pp>, greater<pp>> fila; // Fila de prioridade, MENOR no TOPO
    fila.push(pp(distancia[S], S));                   // pp.first é DISTANCIA, pp.second é VERTICE

    while (true)
    {
        int davez = -1;
        // seleciona o vizinho mais proximo
        while (!fila.empty())
        {

            int atual = fila.top().second;
            fila.pop();

            if (!processado[atual])
            { // podemos usar esse vértice porque ele ainda não foi processado
                davez = atual;
                break;
            }

            // se não, continuamos procurando
        }

        if(davez == -1) break; // se não achou ninguém, é o FIM do ALGORITMO
        processado[davez] = true; // marcamos para não voltar para este vértice

        // agora, ATUALIZAMOS AS DIST se forem MENORES.
        for(int i = 0;i < (int)adjascente[davez].size();i++){
			int dist  = adjascente[davez][i].first; // PESO
			int atual = adjascente[davez][i].second; // VERTICE 
			
			// A nova possível distância é distancia[davez] + dist.
			// Comparamos isso com distancia[atual]
			
			if( distancia[atual] > distancia[davez] + dist ){  // vemos que vale a pena usar o vértice davez
				distancia[atual] = distancia[davez] + dist; // atualizamos a distância
				fila.push( pp (distancia[atual], atual) );  // inserimos na fila de prioridade
			}
		}
    }
}

int main()
{
    cin >> n >> m; // 'n' vertices e 'm' arestas
    int a, b, peso;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> peso;
        adjascente[a].push_back(make_pair(peso, b));
        adjascente[b].push_back(make_pair(peso, a));
    }

    dijkstra(0);
    
    cout << distancia[n+1] << endl;
}