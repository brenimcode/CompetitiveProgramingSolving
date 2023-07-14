#include <iostream>

using namespace std;

int main(){
    int n,*vet,i,j,d,v=0;
    cin >> n;
    if(n <3 && n>10000){
        return 0;
    }
    vet = new int[n];
    for (i = 0; i < n; i++)
    {
        cin >> vet[i]; // 0 se cor, -1 se nao cor
        if(vet[i] == 0){
            v = 1;
        }
    }
    if(v == 0){
        return 0; //verificando se pelo menos um é igual a 0
    }

    for (i = 0; i < n; i++)
    {
        d = 0;
        if(vet[i] == -1){
            for (j = 0; j < n; j++)
            {
                    if(vet[j] == 0){
                        if(d > abs(i-j)){
                            d = abs(i-j);
                            vet[i] = d;
                                if(d >9){
                                vet[i] = 9;
                                }
                        }
                        else if(d == 0){
                            d = abs(i-j);
                            vet[i] = d;
                        }   
                    }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ",vet[i]);
    }
    delete vet;
}