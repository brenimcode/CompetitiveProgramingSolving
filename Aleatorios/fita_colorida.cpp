#include <iostream>
#include <cmath> 
#include <stdlib.h>

using namespace std;

int main(){
    int n,i,j,k,temp;
    cin >> n;
    int vet[n];
    int colorido[n];

    for ( i = 0; i < n; i++)
    {
        cin >> vet[i];
        colorido[i] = 0;   
    }
    //qual a distancia minima para o tom 0
    // [i] [] [] []
    for (i = 0,k=0; i < n; i++)
    {
            temp = 10000;
        for (j = 0; j < n; j++)
        {
            if(vet[j] == 0){
                if(temp > abs(i-j)){
                    temp = abs(i-j);
                }
            }
        }
        if(temp > 9){
            temp = 9;
        }
        colorido[k] = temp;
        k++;

       // cout << "<< " << colorido[i] << " >>" << endl;
    }
    for (i = 0; i < n; i++)
    {
        cout << colorido[i] << " ";
    }
}