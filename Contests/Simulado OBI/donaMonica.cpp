#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define INF (int)1e9 // INFINITO!
#define int long long
#define NMAX 1000

int32_t main() {
    int M,A,B,C; // M = mae, A = Filho A, B = Filho B, C = Filho C
    cin >> M >> A >> B;
    C = M - A - B;
    // A + B + C = M A soma da idade dos filhos NESTE ano é igual a idade da MAE
    if(C >=A && C>= B){
        cout << C << endl;
    }
    else if(A>=C && A>=B){
        cout << A << endl;
    }
    else{
        cout << B << endl;
    }

    return 0;
}