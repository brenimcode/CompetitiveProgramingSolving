#include <bits/stdc++.h>

using namespace std;

#define NMAX 1010

vector <int> grafo[NMAX];
int dist[NMAX];
int cont;

void BFS(int x){

	queue<int> fila;
	fila.push(x); // fila da nossa BFS, começa colocando o vertice X
	dist[x] = x; // colocamos o valor adequado aqui

	while(!fila.empty()){ // Enquanto a fila nao for vazia

		// vamos trabalhar com o primeiro da fila
		int v = fila.front();
		fila.pop(); // para movermos o elemento da fila

		for(int i = 0;i < (int)grafo[v].size();i++){

			int u = grafo[v][i];
			if(dist[u] == -1)   {

				// se u ainda n�o tiver sido visitado, o acrescentamos a fila
				dist[u] = v;
				fila.push(u);
			}
		}
	}
}


int main(){

    /*
    1: 2 -> 3
    2: 4->5
    3: -> NULL
    4: -> NULL
    5: -> NULL


    */int i;
    for(i=0;i<6;i++){
        dist[i] = -1;
    }

    grafo[1].push_back(2); grafo[1].push_back(3); //Vertice 1 se liga ao V[2] e V[3]
    grafo[2].push_back(4); grafo[2].push_back(5); // Vertice 2 se liga ao V[4] e V[5]
    int n;
    cin >> n;
    BFS(1);

    for (int i = 1; i < n; i++)
    {
        printf("Vertice = [%d] -> Distancia de V(1) = [%d]\n",i,dist[i]);
    }



}
