#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    //a^b mod c = [(a mod c) * (a mod c) (b vezes)] mod c
    ll a,b,c,i,nova_b;
    cin >> a >> b >> c;
    ll resultado, pot;
    pot = a % c;
    resultado = 1;

    for ( ; b > 0; b /= 2) {
        if (b % 2 == 1)
            resultado = (resultado * pot) % c;
        pot = (pot * pot) % c;
    }

  printf("%lld\n", resultado);
}
