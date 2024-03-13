#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;// para não termos que digitar pair<int, int> várias vezes,
// fazemos isso para deixar o código mais organizado

//---------------------
#define MAXN 105
#define INFINITO 999999999

int n; // DIMENSAO da matriz
int distancia[MAXN][MAXN];  // o array de distâncias à fonte
int processado[MAXN][MAXN]; // o array que guarda se um vértice foi processado
vector<pii> vizinhos[MAXN]; // nossas listas de adjacência. O primeiro elemento do par representa a distância e o segundo representa o vértice
int mat[MAXN][MAXN];
//---------------------

void Dijkstra(int x, int y){
	for(int i = 0;i <= n;i++) for(int j = 0;j <= n;j++) distancia[i][j] = INFINITO;
	distancia[x][y] = 0; // Assim, garantimos que o primeiro vértice selecionado será o próprio S.
	
	priority_queue< pii, vector<pii>, greater<pii> > fila; // Criamos uma fila de prioridade onde o menor fica no topo.
	fila.push( pii(distancia[S], S) );// Como se pode ver, colocamos o primeiro elemento como sendo a distância do
	// vértice a S e o segundo como sendo o próprio vértice (dist, Vi)
	
	while(true){ // rodar "infinitamente"
		
		int davez = -1;
		int menor = INFINITO;
		
		// selecionamos o vértice mais próximo
		while(!fila.empty()){
			
			int atual = fila.top().second;
			fila.pop();
			
			if(!processado[atual]){ // podemos usar esse vértice porque ele ainda não foi processado
				davez = atual;
				break;
			}
			
			// se não, continuamos procurando
		}
		
		if(davez == -1) break; // se não achou ninguém, é o fim do algoritmo
		
		processado[davez] = true; // marcamos para não voltar para este vértice
		
		// agora, tentamos atualizar as distâncias
		for(int i = 0;i < (int)vizinhos[davez].size();i++){
			
			int dist  = vizinhos[davez][i].first;
			int atual = vizinhos[davez][i].second;
			
			// A nova possível distância é distancia[davez] + dist.
			// Comparamos isso com distancia[atual]
			
			if( distancia[atual] > distancia[davez] + dist ){  // vemos que vale a pena usar o vértice davez
				distancia[atual] = distancia[davez] + dist; // atualizamos a distância
				fila.push( pii(distancia[atual], atual) );  // inserimos na fila de prioridade
			}
		}
	}
	
}

int main(){
	int i,j;
	cin >> n;

	for( i = 0;i < n;i++){
        for ( j = 0; j < n; j++)
        {
            cin  >> [i][j];
        }
        
	}
	int i_inicio = 0, i_fim = 0;
    int j_inicio = n-1, j_fim = n-1; 

	Dijkstra(i_inicio,i_fim); // rodamos o Dijkstra
	cout << distancia[j_inicio][j_fim] << endl; // imprimimos a resposta
	
	return 0;
}

