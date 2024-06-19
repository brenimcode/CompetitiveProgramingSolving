#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000100;
#define int long long

int bit[MAXN], n, q;

// Incrementa v em bit[x]
void upd(int x, int v) {
    // Itera sobre todos indices "relevantes"
    while (x <= n) {
        bit[x] += v;
        x += (x & -x);
    }
}

// Retorna a soma de [1, x]
int soma(int x) {
    int ans = 0;
    while (x > 0) {
        ans += bit[x];
        x -= (x & -x);
    }
    return ans;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    // Inicializa o BIT com zeros
    for (int i = 0; i <= n; i++) {
        bit[i] = 0;
    }

    char o;
    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> o >> a;
        if (o == '?') {
            if (a == 0) {
                cout << 0 << endl;  // Soma de um intervalo vazio é 0
            } else {
                cout << soma(a) << endl;
            }
        } else if (o == '+') {
            cin >> b;
            upd(a + 1, b);  // Incrementa o índice a+1 por b
        }
    }

    return 0;
}
