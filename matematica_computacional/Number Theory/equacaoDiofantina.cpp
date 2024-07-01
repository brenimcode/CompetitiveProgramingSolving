#include <bits/stdc++.h>

using namespace std;
#define int long long

// Algoritmo de Euclides Estendido para encontrar (x, y) tal que ax + by = mdc(a, b)
int extEuclides(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int mdc = extEuclides(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return mdc;
}

int32_t main() {
    // Programa que resolve equações Diofantinas: ax + by = c
    int a, b, c;
    cin >> a >> b >> c;

    int x, y;
    int mdc = extEuclides(a, b, x, y);

    // Existe Solução SE E SOMENTE SE mdc(a, b) | c
    if (c % mdc != 0) {
        cout << -1 << endl;
        return 0;
    }
    // Encontrar a solução particular
    x *= c / mdc;
    y *= c / mdc;

    // Ajustar a solução particular para encontrar todas as soluções se necessário
    cout << 1 << endl << x << ' ' << y << endl;
    // Outras soluções podem ser obtidas pela fórmula:
    // x = x0 + k*(b/mdc), y = y0 - k*(a/mdc) para qualquer inteiro k

    return 0;
}
