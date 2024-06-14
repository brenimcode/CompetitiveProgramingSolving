#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main(){

    double c,d,t; // d = distancia do aero, c = consumo do carro em km por LITRO, T = numero d elitros de comb, presente no tanque antes do abastecimento
    cin >> c >> d >> t;


    double result = (d/c) - t;

    if(result < 0){
        result = 0;
    }

    printf("%.1f", result);

}