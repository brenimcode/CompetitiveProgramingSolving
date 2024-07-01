#include <bits/stdc++.h>

using namespace std;
#define int long long


int mdc(int a, int b){
    if(b == 0) return a;
    return mdc(b,a%b);
}

int mmc(int a,int b){
    return (a*b)/mdc(a,b);
}


int32_t main(){
    int c,d,q; // C = valor maximo da calc, D = dividendo, Q = divisor
    cin >> c >> d >> q;
    // Ver se a fração é irredutivel, se for "IMPOSSIVEL" se nao mostra a fração irredutivel desses valores.
    int MDC = mdc(q,d);
    d /= MDC;
    q /= MDC;

    if( d > c || q > c){
        cout << "IMPOSSIVEL" << endl;
    }
    else{
        cout << d << ' ' << q << endl;
    }
    
}