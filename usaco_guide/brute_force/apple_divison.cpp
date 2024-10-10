#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<long long> pesos;

ll distribui_macas(int indice, ll soma1, ll soma2) {
    // Se já adicionamos todas as maçãs, retorna a diferença absoluta entre os dois grupos
    if (indice == n) { return abs(soma1 - soma2); }

    // Tenta adicionar a maçã atual ao primeiro ou ao segundo grupo
    return min(distribui_macas(indice + 1, soma1 + pesos[indice], soma2),
               distribui_macas(indice + 1, soma1, soma2 + pesos[indice]));
}

int main() {
    cin >> n;
    pesos.resize(n);
    for (int i = 0; i < n; i++) { cin >> pesos[i]; }

    // Resolve o problema começando na maçã 0 com ambos os grupos vazios
    cout << distribui_macas(0, 0, 0) << endl;
}