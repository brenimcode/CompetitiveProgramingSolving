#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010
#define pp pair<int, int>
#define INF 999999
int n, m,origem,destino;   // n vertices, m arestas,vertices destino,origem.

int distancia[MAXN];  // o array de distâncias à ORIGEM
int processado[MAXN]; // o array que guarda se um vértice foi PROCESSADO

vector<pp> adjascente[MAXN]; // LISTA DE ADJ. OU VIZINHOS.

void dijkstra(int S)
{
    for (int i = 1; i <= n; i++) distancia[i] = INF; // Definindo todas distancias como INFINITO, inicialmente
    distancia[S] = 0;// distancia da ORIGEM -> ORIGEM é 0.

    priority_queue<pp, vector<pp>, greater<pp>> fila; // Fila de prioridade, MENOR no TOPO
    fila.push(pp(distancia[S], S));                   // pp.first é DISTANCIA, pp.second é VERTICE

    while (true)
    {
        int davez = -1; // seleciona o vizinho mais proximo
        while (!fila.empty())
        {
            int atual = fila.top().second; //Pego o atual VERTICE.
            fila.pop();

            if (!processado[atual])
            { // podemos usar esse vértice porque ele ainda não foi processado
                davez = atual;
                break;
            }
            // se não, continuamos procurando
        }

        if(davez == -1) break; // se não achou ninguém, é o FIM do ALGORITMO
        processado[davez] = true; // marcamos como PROCESSADO para não voltar para este vértice

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
    cin >> origem >> dest; //le a origem e o destino
    int a, b, peso;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> peso;
        adjascente[a].push_back(make_pair(peso, b));
        adjascente[b].push_back(make_pair(peso, a));
    }

    dijkstra(origem);

    cout << distancia[dest] << endl;
}