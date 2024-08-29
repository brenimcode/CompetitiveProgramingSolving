#include <bits/stdc++.h>
using namespace std;

#define NMAX 200100
#define int long long

vector<int> bit_zero; // Para contar zeros
vector<int> bit_neg;  // Para contar negativos
vector<int> vet;
int n, q;

// Atualiza a BIT de contagem
void upd(vector<int> &bit, int x, int v) {
    while (x <= n) {
        bit[x] += v;
        x += (x & -x);
    }
}

// Consulta a BIT de contagem
int query(const vector<int> &bit, int x) {
    int res = 0;
    while (x > 0) {
        res += bit[x];
        x -= (x & -x);
    }
    return res;
}

// Consulta o intervalo na BIT de contagem
int query_interval(const vector<int> &bit, int i, int j) {
    return query(bit, j) - query(bit, i - 1);
}

// Define um novo valor na sequência
void sets(int x, int v) {
    if (vet[x] == 0) {
        upd(bit_zero, x, -1);
    } else if (vet[x] < 0) {
        upd(bit_neg, x, -1);
    }
    if (v == 0) {
        upd(bit_zero, x, 1);
    } else if (v < 0) {
        upd(bit_neg, x, 1);
    }
    vet[x] = v;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> q) {
        bit_zero.assign(n + 1, 0);
        bit_neg.assign(n + 1, 0);
        vet.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            vet[i] = x;
            if (x == 0) {
                upd(bit_zero, i, 1);
            } else if (x < 0) {
                upd(bit_neg, i, 1);
            }
        }

        char option;
        int a, b;
        string result = "";
        for (int i = 0; i < q; i++) {
            cin >> option >> a >> b;
            if (option == 'C') {
                sets(a, b);
            } else {
                int zero_count = query_interval(bit_zero, a, b);
                if (zero_count > 0) {
                    result += '0';
                } else {
                    int neg_count = query_interval(bit_neg, a, b);
                    if (neg_count % 2 == 0) {
                        result += '+';
                    } else {
                        result += '-';
                    }
                }
            }
        }
        cout << result << endl;
    }

    return 0;
}
