#include <bits/stdc++.h>
using namespace std;

#define par pair<int, int>	// (i,j)
typedef pair<int, par> pii; // par(distancia, (x,y))
#define MAXN 105
#define INF 9999997

int n;						// DIMENSAO da matriz
int dist[MAXN][MAXN];		// o array de distâncias à fonte
vector<pii> vizinhos[MAXN]; // nossas listas de adjacência. O primeiro elemento do par representa a distância e o segundo representa o vértice
int mat[MAXN][MAXN];
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Usado para rodar pelos VIZINHOS:
int dlinha[4] = {0, 0, 1, -1};
int dcoluna[4] = {1, -1, 0, 0};

int Dijkstra()
{
	memset(dist, INF, sizeof(dist)); // inicializa TODOS C INFINITO
	dist[1][1] = 0;					 // Assim, garantimos que o primeiro vértice selecionado será o próprio S.

	priority_queue<pii, vector<pii>, greater<pii>> fila; // Criamos uma fila de prioridade onde o menor fica no topo.

	fila.push(pii(0, par(1, 1))); // coloco o primeiro na fila, DIST = 0, e vertice = (1,1)

	while (!fila.empty())
	{
		// pega o elemento topo, e tira
		int d = fila.top().first, i = fila.top().second.first, j = fila.top().second.second;
		fila.pop();

		// se o elemento já tiver sido processado,continue.
		if (d > dist[i][j]) continue;
		
		for (int k = 0; k < 4; k++)
		{
			int iV = i + dlinha[k]; // Fazendo isso vamos pegar todos os adjascentes
			int jV = j + dcoluna[k];
			// vejo se ele está no limite da matriz
			if (iV >= 1 && iV <= n && jV >= 1 && jV <= n && mat[iV][jV] + dist[i][j] < dist[iV][jV])
			{
				dist[iV][jV] = mat[iV][jV] + dist[i][j];
				// adiciono na fila para o processa-lo
				fila.push(pii(dist[iV][jV], par(iV, jV)));
			}
		}
	}
	return dist[n][n];
}

	int main()
	{
		int i, j;
		cin >> n;

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				cin >> mat[i][j];
			}
		}
		
		cout << Dijkstra() << endl; // imprimimos a resposta

	for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				cout << dist[i][j] << ' ';
			}
			cout << endl;
		}

		return 0;
	}
