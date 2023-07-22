#include <iostream>
#include <cmath>
using namespace std;

int hanoi(int n){
    return pow(2,n)-1;
}

int main(){
    int N,tamanho=0,*vet,i=0;
    vet = (int*) malloc(100*sizeof(int));
    while(N != 0){
        cin >> N;
        tamanho++;
        vet[i] = N;
        i++;
    }
    vet = (int*) realloc(vet,tamanho*sizeof(int));
    for (i = 0; i < tamanho-1; i++)
    {
        cout << "Teste " << i+1 << endl << hanoi(vet[i]) << endl;
    }
    free(vet);
}