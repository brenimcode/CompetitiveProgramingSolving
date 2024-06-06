#include <bits/stdc++.h>

using namespace std;

#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

// Função para comparar se dois números em ponto flutuante são próximos o suficiente
bool isEqual(long double a, long double b, long double epsilon = 1e-9) {
    return abs(a - b) < epsilon;
}

int32_t main()
{
    _
    long double ax, bx, ay, by; // vetores
    cin >> ax >> ay >> bx >> by;

    // Calcular o produto escalar
    long double produto = ax * bx + ay * by;
    // Calcular os módulos dos vetores
    long double moduloA = sqrt(ax * ax + ay * ay);
    long double moduloB = sqrt(bx * bx + by * by);

    // Verificar se os vetores são paralelos, perpendiculares ou nem paralelos nem perpendiculares
    if (isEqual(produto / (moduloA * moduloB), 0.0)) {
        cout << "-1" << endl; // Perpendiculares
    } else if (isEqual(produto / (moduloA * moduloB), 1.0)) {
        cout << "1" << endl; // Paralelos
    } else {
        cout << "0" << endl; // Nem paralelos, nem Perpendiculares
    }

    return 0;
}
