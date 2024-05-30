#include <bits/stdc++.h>

using namespace std;

#define NMAX 27

vector <char> grafo[NMAX];
 // 'A' -> 'B'
 // 'B' -> 'A' , 'C'


int componente[NMAX];
int cont;
int num_componentes;
vector <int> comp;

void dfsR(int vertice){
    
    for (int a = 0; a < (int) grafo[vertice].size(); a++)
    {
        int adjascente = grafo[vertice][a];
        if(componente[adjascente] == -1){
            componente[adjascente] = componente[vertice]; // Todos q eu consigo chegar pelo 0, vai ser componente 0, 
            dfsR(adjascente);

        }
    }

}

void GrafoDSR(int n){
    cont=0,num_componentes=0;//Para assinar em qual momento o vertice foi visitado.
    int i;
    for(i = 0;i<n;i++){
        componente[i] = -1;
    }

    // 1 = [-1], 2 = [-1], 3 = [-1] ...


    for(i = 0;i<n;i++){
        if(componente[i] == -1){
            num_componentes++; 
            componente[i] = i; // Componente[0] = 0; [0] [0] [0] [0] [0] [6]
            comp.push_back(componente[i]); // [0] [6]
            dfsR(i);
        }
    }
}

int main(){

    int n,V,E,i,j,k;
    cin >> n;
    int caso = 1;
    char a,b;
    for ( i = 1; i <= n; i++)
    {
        cin >> V >> E; // Vertices e EDGES(ARESTAS)
        printf("Case #%d:\n\n",caso++);
        for(j=0;j<E;j++){
            
            cin >> a;
            cin >> b;
             //CHAR A E B //'a' representa o 0
            // (a,b)
            grafo[a-'a'].push_back(b-'a');
            grafo[b-'a'].push_back(a-'a');

        }
        GrafoDSR(V); //preenche as componentes
        for (k = 0; k < num_componentes; k++)
        {

                for (j = 0; j < V; j++)
                {
                    if(componente[j] == comp[k])
                        printf("%c,",j+'a');

                }
                printf("\n");
        }


        printf("%d connected components\n",num_componentes);

        for (j = 0; j < V; j++)
        {
            grafo[j].clear(); //Limpa todo o grafo.
        }
        comp.clear();
        
        
    }
    

}