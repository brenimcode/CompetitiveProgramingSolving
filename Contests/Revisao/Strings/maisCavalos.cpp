#include <bits/stdc++.h>

#define DEBUG(x) cout << #x << " >>>> " << x << endl

using namespace std;

int main() {
    string a,b;

    cin >> a >> b;

    int a_coluna = a[0] - 'a' + 1;
    int a_linha = a[1] - '0';

    int b_coluna = b[0] - 'a' + 1;
    int b_linha = b[1] - '0';
    

    int AbsCol = abs(a_coluna - b_coluna);
    int AbsLin = abs(a_linha - b_linha);


    if((AbsCol == 2 && AbsLin == 1) || (AbsCol == 1 && AbsLin == 2)){
        cout << "VALIDO" << endl;
    }
    else{
        cout << "INVALIDO" << endl;
    }
    
    return 0;
}
