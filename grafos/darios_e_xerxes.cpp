#include <bits/stdc++.h>

using namespace std;


int main() {
    int x,i,j;
    int aux1, aux2;
    int dario=0,xerxes=0;
    bool relacoes[4][4];
    memset(relacoes, 0, sizeof(relacoes)); //inicializando com 0
    relacoes[0][1] = 1;
    relacoes[0][2] = 1;
    relacoes[4][0] = 1;
    relacoes[4][1] = 1;
    relacoes[2][4] = 1;
    relacoes[2][3] = 1;
    relacoes[3][4] = 1;
    relacoes[3][0] = 1;
    relacoes[1][3] = 1;
    relacoes[1][2] = 1;

    cin >> x;

    for(i=0;i<x;i++){
        cin >> aux1 >> aux2;

        if(relacoes[aux1][aux2]){
            dario++;
        }
        if(relacoes[aux2][aux1]){
            xerxes++;
        }
    }

    if(xerxes>dario) cout << "xerxes\n";
    else cout << "dario\n";



    return 0;
}
