#include <bits/stdc++.h>

using namespace std;

#define MAXN 10001

vector <int> aux;
vector <int> vet;

void merge(int esq, int meio, int dir){
    int it_aux=esq;
    int fim_esq = meio-1;
    int i;
    int tam = dir-esq+1;

    while(esq <= fim_esq && meio <= dir){
        if(vet[esq] >= vet[meio])
            aux[it_aux++] = vet[esq++]; //andando pra frente com o aux( que esta ordenando) e Vet(parte esquerda)
        else
            aux[it_aux++] = vet[meio++]; //andando pra frente com o aux( que esta ordenando) e Vet(parte Direita)       
    }
    //agora colocar o que restou de uma das duas pilhas,
    while(esq <= fim_esq){
        aux[it_aux++] = vet[esq++];
    }
    
    while(meio <= dir){
        aux[it_aux++] = vet[meio++];
    }
    for (i = 0; i < tam ; i++)
    {
        vet[dir] = aux[dir];
        dir--;//é feito com dir e nao com esq, pois esq foi perdido durante o algoritmo, entao copia-se pelo ultimo.
    }
    

}

void mergeSort(int esq,int dir){
    int meio;
    if(dir > esq){
        meio = (dir+esq)/2;
        mergeSort(esq,meio);
        mergeSort(meio+1,dir);
        merge(esq,meio+1,dir);
    }
}

int main()
{
    int n;
    cin >> n;
    aux.resize(n);
    vet.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
        aux[i] = 0;
    }
    
    mergeSort(0,n-1);

    for (int i = 0; i < n; i++)
    {
        cout << vet[i] << ' ';
    }

    return 0;
}
