#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> bit;
vector<int> position;
vector<int> vet;

// Função para atualizar a Fenwick Tree
void upd(int idx, int delta, int n) {
    while (idx <= n) {
        bit[idx] += delta;
        idx += idx & -idx;
    }
}

// Função para calcular a soma prefixada na Fenwick Tree
int soma(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= idx & -idx;
    }
    return sum;
}

// Função de troca atualizada para ser mais eficiente
void troca(int x, int top, int n) {
    int old_pos = vet[x];
    int new_pos = top;

    // Remove o elemento da posição antiga
    upd(old_pos, -1, n);

    // Adiciona o elemento na nova posição
    upd(new_pos, 1, n);

    // Atualiza a posição do filme
    vet[x] = new_pos;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;

    while (cases--) {
        int n, q;
        cin >> n >> q;

        bit.assign(n + q + 1, 0);
        vet.assign(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            vet[i] = q + i;
            upd(q + i, 1, n + q);
        }

        int current_top = q;
        for (int i = 1; i <= q; i++) {
            int aux;
            cin >> aux;

            cout << soma(vet[aux] - 1) << " "; // O(log n)

            // Move o filme para o topo
            troca(aux, current_top, n + q); // O(log n)

            current_top--;
        }
        cout << endl;
    }

    return 0;
}
