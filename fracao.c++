#include <bits/stdc++.h>

using namespace std;

long long mdc(long long a, long long b) {
    return (b == 0 ? a : mdc(b, a % b));
}

int main() {
    long long a, b, c, d, div, sum, aux;
    cin >> a >> b >> c >> d;
    div = b * d;
    a = a * d;
    c = c * b;
    sum = a + c;
    aux = mdc(sum, div);
    while (aux > 1) {
        sum /= aux;
        div /= aux;
        aux = mdc(sum, div);
    }
    cout << sum << ' ' << div;
    return 0;
}
