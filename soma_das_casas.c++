#include <bits/stdc++.h>

using namespace std;

int n,i,vet[101000000];

int busca_binaria(int num){
    int ini = 1,meio,fim = n;
    while(ini <= fim){
        meio = (ini+fim)/2;
        if(vet[meio] == num) return meio;
        if(vet[meio] < num) ini = meio+1;
        if(vet[meio] > num) fim = meio-1;
    }
}



int main()
{
    int soma,j,aux;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    cin >> soma;

    

    return 0;
}