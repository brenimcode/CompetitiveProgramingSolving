#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > grafo;
int ok;

int voodoo(int no) // Esta função recursiva percorre o grafo e verifica se todos os submóbiles têm o mesmo número de peças
{
    int i,n,peso,atual,total; // Variáveis para controle do número de peças
    
    n = (int)grafo[no].size(); // Obtém o número de submóbiles do nó atual
    total = 1; // Inicializa o total de peças do submóbile atual como 1, considerando o próprio nó
    for(i = 0; i < n; i++)
    {
        atual = voodoo(grafo[no][i]); // Chama recursivamente a função para cada submóbile
        if (!i) peso = atual; // No primeiro submóbile, armazena o número de peças
        else if (atual != peso) ok = 0; // Se o número de peças for diferente do primeiro submóbile, marca o móbile como desbalanceado
        total += atual; // Soma o número de peças do submóbile atual ao total
    }
    return(total); // Retorna o total de peças do submóbile
}


int main(void)
{
    int N,i,u,v;
    
    scanf("%d",&N);
    grafo.resize(N+1);
    for(i = 0; i < N; i++)
    {
        scanf("%d %d",&u,&v);
        grafo[v].push_back(u);
    }
    ok = 1;
    voodoo(0);
    printf("%s\n",ok ? "bem" : "mal");
    for(i = 0; i < N; i++)
    {
        for(int j = 0; j < (int) grafo[i].size(); j++)
        {
       printf("grafo[%d] - [%d]\n",i,grafo[i][j]);
        }
    }

    return(0);
}
