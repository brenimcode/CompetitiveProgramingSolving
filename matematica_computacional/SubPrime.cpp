#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define int long long

int32_t main() {
    _

    int b, n; // B = BANCOS, bancos são inteiros de 1 a B, N = DEBENTURES,
    // Se cada banco B[i] pagar os empréstimos somente com RESERVA monetária, todos os bancos sobreviverão,
    while (cin >> b >> n) {
        if (b == 0 && n == 0) break;

        int bancos[b+2];
        for (int i = 1; i <= b; i++) {
            cin >> bancos[i]; // leitura das reservas monetárias
        }

        int devedor, credor, valor;
        bool ver = true;
        for (int i = 0; i < n; i++) {
            cin >> devedor >> credor >> valor; // leitura do BANCO devedor, BANCO credor, Valor da debênture
            
            // Verifica se é possível liquidar todos as debêntures sem intervenção do Banco Central da Nlogônia
            bancos[devedor] -= valor;
            bancos[credor] += valor;
        }

        for (int i = 1; i <= b; i++) {
            if (bancos[i] < 0) { // Se algum banco tiver reservas monetárias negativas, a solução não é possível
                ver = false;
                break;
            }
        }

        if (ver) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }
    }

    return 0;
}
