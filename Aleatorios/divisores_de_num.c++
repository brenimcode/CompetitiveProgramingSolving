#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,i,soma=0,soma_divisores=0;
    vector <int> divisores;
    cin >> a;
    for (i = 1; i <= a; i++)
    {
        if(a%i == 0){
            divisores.push_back(i);
            soma++;
            soma_divisores += i;
        }
    }
    printf("%d divisor(es): ",soma);
    for (i = 0; i < soma; i++)
    {
        printf("%d ",divisores[i]);
    }
    printf("\nSoma de divisores = %d\n",soma_divisores);
    if(soma == 2){
        printf("Primo");
    }
    else{
        printf("Nao primo");
    }

}