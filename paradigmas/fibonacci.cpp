#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> par;
#define DEBUG(x) cout << #x << " = " << x << endl;
#define int long long

const int MAXN = 40;
int qtd;

int fibonacci(int x) {
    qtd++; // Incrementa o contador a cada chamada
    if (x == 0) return 0;
    if (x == 1) return 1;
    return fibonacci(x - 1) + fibonacci(x - 2);
}

int32_t main() {
    int n, aux;
    cin >> n;


    while (n--) {
        cin >> aux;
        qtd = 0; // Reseta o contador antes de cada chamada
        int result = fibonacci(aux);
        cout << "fib(" << aux << ") = " << --qtd << " calls = " << result  << endl;
    }

    return 0;
}
