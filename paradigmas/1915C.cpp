#include <bits/stdc++.h>

using namespace std;

#define NMAX 8
#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define int long long

bool ehQuadradoPerfeito(int n) {
    if (n < 0)
        return false; // Números negativos não têm raiz quadrada perfeita

    int raiz = sqrt(n); // Calcula a raiz quadrada de n
    return (raiz * raiz == n); // Verifica se o quadrado da raiz é igual a n
}


int32_t main()
{
    int t,n;

    cin >> t;

    while(t--){
        cin >> n;
        int sum = 0;
        while(n--){
            int aux;
            cin >> aux;
            sum+=aux;
        }

        if(ehQuadradoPerfeito(sum)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }

    return 0;
}