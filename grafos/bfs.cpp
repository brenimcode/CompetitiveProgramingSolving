#include <bits/stdc++.h>

using namespace std;

#define NMAX 1010

vector <int> grafo[NMAX];
int dist[NMAX];
int cont;

void BFS(int x){ // Faz uma busca em largura a partir do vertice X ( O (n+m) )
    memset(dist,-1, sizeof dist);
	queue<int> fila; // fila para armazenar os vertices.
	fila.push(x); // fila da nossa BFS, começa colocando o vertice X
	dist[x] = 0; // colocamos o valor adequado aqui

	while(!fila.empty()){ // Enquanto a fila nao for vazia

		// vamos trabalhar com o primeiro da fila
		int v = fila.front();
		fila.pop(); // para movermos o elemento da fila

        for(auto viz : grafo[v]){
			if(dist[viz] == -1)   {
				// se viz ainda nao tiver sido visitado, o acrescentamos a fila
				dist[viz] = v;
				fila.push(viz);
			}
		}
	}
}


int main(){

    /*
    1: 2, 3
    2: 4,5
    3: -> NULL
    4: -> NULL
    5: -> NULL
    */
   
   int i;

    grafo[1].push_back(2); grafo[1].push_back(3); //Vertice 1 se liga ao V[2] e V[3]
    grafo[2].push_back(4); grafo[2].push_back(5); // Vertice 2 se liga ao V[4] e V[5]
    int n;
    cin >> n;


    BFS(1); // Vertice 1 chamo BFS

    for (int i = 1; i <= n; i++)
    {
        printf("Vertice = [%d] -> Distancia de V(1) = [%d]\n",i,dist[i]);
    }



}
