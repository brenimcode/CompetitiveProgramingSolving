#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c; // -1: bomba 1: desarme 0: outro poder
    // desarme e não estiver no topo: 1, se bomba no topo 2, desarme no topo entao 3
    if(a != 1 && (b == 1 || c == 1)) cout << 1 << endl;
    else if(a == 1) cout << 3 << endl;
    else if(a == -1) cout << 2 << endl;
    else cout << 3 << endl;

    // 1 - embaralhar, colocar o embaralhe no topo e comprar a nova primeira carta
    // 2 - pular a vez
    // 3 -  comprar a carta do topo.
    return 0;
}
// deve 1, 4, deve :5 , devem para ele: 3