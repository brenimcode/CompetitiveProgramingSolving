#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " ----->  " << x << endl

bool eh_potencia_de_2(int x) {
    return (x > 0) && ((x & (x - 1)) == 0);
}

int32_t main() {
    int n, q;
    cin >> n >> q;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> prefix_soma_potencia_2(n + 1, 0), prefix_soma_impar(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        prefix_soma_potencia_2[i] = prefix_soma_potencia_2[i - 1] + (eh_potencia_de_2(A[i - 1]) ? A[i - 1] : 0);
        prefix_soma_impar[i] = prefix_soma_impar[i - 1] + (A[i - 1] % 2 != 0 ? A[i - 1] : 0);
    }

    // Processar as consultas
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        l--; r--;

        int soma_potencias_2 = prefix_soma_potencia_2[r + 1] - prefix_soma_potencia_2[l];
        int soma_impares = prefix_soma_impar[r + 1] - prefix_soma_impar[l];

        if (soma_potencias_2 > soma_impares) {
            cout << 'A' << endl;
        } else if (soma_potencias_2 < soma_impares) {
            cout << 'B' << endl;
        } else {
            cout << 'E' << endl;
        }
    }

    return 0;
}
