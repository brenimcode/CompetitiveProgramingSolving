#include <bits/stdc++.h>

using namespace std;

// Debug macro for printing variable values (optional, can be removed in production)
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main() {
    // Variable declarations
    double B,T; 
    cin >> B >> T;

     // 160cm = base, 70cm = altura
     // FELIX pega ESQUERDA = 1, Marz pega DIREITA = 2, Metade metade = 0
     // area = 11.200cm²
        // 50*70=3500 + (T-B)*70/2 == 4760
        //
        double area1; 
        if(T > B) {
             area1 = B*70.0000 + (abs(T-B)*70.0000)/2.0000;
        }
        else{
            area1 = T*70.0000 + (abs(T-B)*70.0000)/2.0000;
        }

    double area2 = 11200.0000 - area1;
    if(area1 == area2) {
        cout << 0 << endl;
    }

    if(area1 > area2){
        cout << 1 << endl;
    }

    if (area1 < area2){
        cout << 2 << endl;
    }

    return 0;
}
