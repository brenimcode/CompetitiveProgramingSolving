#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    string aux;
    getline(cin, aux);

    int qtd_t = 0, qtd_a = 0, qtd_u = 0, qtd_p = 0;
    
    for (char letra : aux) {
        if (letra == 'T') qtd_t++;
        else if (letra == 'A') qtd_a++;
        else if (letra == 'U') qtd_u++;
        else if (letra == 'P') qtd_p++;
    }

    int TAP = min({qtd_t, qtd_a, qtd_p});
    qtd_t -= TAP;
    qtd_a -= TAP;
    qtd_p -= TAP;

    int TUP = min({qtd_t, qtd_u, qtd_p});

    cout << TAP + TUP << endl;

    return 0;
}
