#include <bits/stdc++.h>

using namespace std;

int n,i,vet[101000000];

int busca_binaria_2(int num){
    int ini = 1,meio,fim = n;
    while(ini <= fim){
        meio = (ini+fim)/2;
        if(vet[meio] == num) return meio;
        if(vet[meio] < num) ini = meio+1;
        if(vet[meio] > num) fim = meio-1;
        if(ini<=fim){
            return meio;
        }
    }
    return -1;
}



int main()
{
    int soma,j,maior,m_i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    maior = vet[n-1];
    cin >> soma;
    //So precisa-se olhar para o vetor até o numero SOMA, ex: S=4, 1,2,3,4,5,6,7,8,9,10,11 corta o {7,8,9,10} e obtem apenas
    if(maior <= soma){
        m_i = n-1;
    }
    else{
        m_i = busca_binaria_2(soma)-1;
    }
    // A gente so ve até o valor soma, ou o maior valor até soma

    
    i=m_i;

    while(i > 0)
    {
        for (j = 0; j < m_i; j++)
        {
            //printf("[%d] -- [%d], i == %d , j == %d\n",vet[i],vet[j],i,j);
            if(vet[i] + vet[j] == soma){
                cout << vet[j] << ' ' << vet[i];
                return 0;
            }
            if(vet[i] + vet[j] > soma){
                break;
            }
        }
        i--;
    }

    

    return 0;
}