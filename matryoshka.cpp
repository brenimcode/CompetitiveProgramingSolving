#include <bits/stdc++.h> // biblioteca magica
#include <iostream>

using namespace std;

int main(){
    int n,*vet,*vet1,i,cont=0,*vetor,k=0;
    cin >> n;
    vet = new int[n];
    vet1 = new int[n];
    vetor = new int[n];
    for (i = 0; i < n; i++)
    {
       cin >> vet[i];
       vet1[i] = vet[i];
    }
    sort(vet,vet+i);

    for ( i = 0; i < n; i++)
    {
        if(vet[i] != vet1[i]){
            cont++;
            vetor[k] = vet[i];
            k++;
        }
        //compara os dois
    }

    printf("%d",cont);
    cout << endl;
    for (k = 0; k < cont; k++)
    {
        cout << vetor[k] << ' ';
    }

    delete [] vet; // liberando a memoria
    delete [] vet1;
    delete [] vetor;
}