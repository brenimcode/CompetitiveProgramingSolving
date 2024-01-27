#include <bits/stdc++.h>

using namespace std;

int InsertionSORT(string vet, int tam){
    int i,j,temp;
    int cont=0;
    // Se ordenado O(N), se não O(N^2)
    for (i = 1; i < tam; i++)
    {
        temp = vet[i];
        for (j = i-1; j >= 0 && vet[j] < temp; j--)
        {
            vet[j+1] = vet[j];
            cont++;
        }
        vet[j+1] = temp;
        
    }
    return cont;

}


int main(){   
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin,s);
        printf("[%d]\n",InsertionSORT(s,s.size()));
    }
    
    return 0;
}
