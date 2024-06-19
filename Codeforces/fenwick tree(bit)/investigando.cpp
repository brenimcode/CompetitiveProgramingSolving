#include <bits/stdc++.h>
using namespace std;

const int NMAX = 100010;

int bit[2][NMAX];  // bit[0] for even count, bit[1] for odd count
int n;

// atualiza a BIT com valor v no V[X]
void upd(int x, int v, int parity) {
    while (x <= n + 1) {  // Ajuste para garantir que x está dentro dos limites da BIT
        bit[parity][x] += v;
        x += (x & -x);
    }
}

// retorna soma [1,X]
int soma(int x, int parity) {
    int res = 0;
    while (x > 0) {
        res += bit[parity][x];
        x -= (x & -x);
    }
    return res;
}

int sum_inter(int x, int y, int parity) {
    return soma(y, parity) - soma(x - 1, parity);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    // inicializa a BIT
    memset(bit, 0, sizeof(bit));
    
    vector<int> bin_seq(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> bin_seq[i];
    }

    int current_parity = 0;
    int result = 0;

    // Increment initial even prefix count
    upd(1, 1, 0);

    for (int i = 1; i <= n; ++i) {
        if (bin_seq[i] == 1) {
            current_parity ^= 1;
        }

        if (current_parity == 1) {
            result += soma(i, 0); // Number of even prefixes up to index i
        } else {
            result += soma(i, 1); // Number of odd prefixes up to index i
        }

        upd(i + 1, 1, current_parity);
    }

    cout << result << endl;

    return 0;
}
