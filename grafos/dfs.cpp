#include <bits/stdc++.h>

using namespace std;

#define NMAX 1010

vector <int> grafo[NMAX];
int visitados[NMAX];
int cont;

void dfsR(int vertice){
    visitados[vertice] = cont++;
    for (int a = 0; a < (int) grafo[vertice].size(); a++)
    {
        int adjascente = grafo[vertice][a]; // adj =  2
        if(visitados[adjascente] == -1)
            dfsR(adjascente);
    }
}

void dfs(int vAtual){
    visitados[vAtual] = cont++; // digo que ele foi visitado 
    for (auto adj : grafo[vAtual]) // para todo vizinho do vertice Atual faço DFS:
    {
        if(visitados[adj] == -1)
            dfs(adj);
    }
}

/*
1 -> 2, 4   [0]
2 -> 1    [1]
3 -> 2     [3]
4 -> /    [2]
*/

void GrafoDSR(int n){

    cont=0;//Para assinar em qual momento o vertice foi visitado.
    int i; 
    for(i = 0;i<n;i++)
        visitados[i] = -1;

    for(i = 1;i<n;i++){
        if(visitados[i] == -1)
            dfsR(i);
    }
}

int i, n;

void dfsTodos(){
    memset(visitados,-1,sizeof visitados);

    for(i = 1;i<n;i++)
        if(visitados[i] == -1)
            dfsR(i);
}


int main(){

    /*
    1: 2 -> 3
    2: 4->5
    3: -> NULL
    4: -> NULL
    5: -> NULL
    
    
    */
    grafo[1].push_back(2); grafo[1].push_back(3); //Vertice 1 se liga ao V[2] e V[3]
    grafo[2].push_back(4); grafo[2].push_back(5);
    int n;
    cin >> n;
    GrafoDSR(n);

    for (int i = 1; i < n; i++)
    {
        printf("Vertice = [%d] -> Visitado em [%d]\n",i,visitados[i]);
    }
    

}