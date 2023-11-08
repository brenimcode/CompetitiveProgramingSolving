#include <iostream>

using namespace std;

int main(){
    int v[5] = {4,1,2,5,3};
    //bubble sort
     int ordenado = 0,temp;
     while(ordenado == 0){
        ordenado = 1;
        for (int i = 0; i < 4; i++)
        {
            if(v[i] > v[i+1]){
                ordenado = 0;
                temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }
        }
        //Bubble sort é recomendado para n <= 10^4
     }
}