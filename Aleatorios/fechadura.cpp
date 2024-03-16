#include <iostream>

using namespace std;

int main(){
    int n,m,*vet,i,cont=0; //n: QTD Pinos da fechadura. m: Altura em que devem ficar para desbloquear
    cin >> n >> m;
    vet = new int[n];
    for(i = 0;i<n;i++){
        cin >> vet[i];
    }
    for(i = 0;i<n;i++){
        //analisa o primeiro elemento e comparar com M
        if(vet[i] != m){
            cont += abs(vet[i] - m);
            if((vet[i] - m) < 0){
                vet[i+1] += abs(vet[i] - m);
                continue;
            }
            vet[i+1] += (m - vet[i]); 
        }
        
    }
    cout << cont;

    delete vet;

}