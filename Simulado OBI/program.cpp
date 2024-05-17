#include <iostream>
#include <vector>
using namespace std;

unsigned long long res = 0;
int lista[501000];
int n, k;
vector<vector<int>> m;

void dp(int ini, int fim, int soma) {
    if (m[ini][fim] != -1) return;
    if (ini > n || fim > n) return;
    if (soma > k) {
        m[ini][fim] = 0;
        return;
    }
    soma += lista[fim];
    if (soma == k) {
        m[ini][fim] = 1;
        res++;
    }
    dp(ini, fim + 1, soma);
    dp(ini + 1, ini + 1, 0);
}

int main() {
    cin >> n >> k;
    m.resize(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++) {
        cin >> lista[i];
    }
    dp(1, 1, 0);
    cout << res << endl;
    return 0;
}
