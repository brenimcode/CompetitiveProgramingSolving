#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,t,m;
    // t = num inicial arvores no dia 0, m = numero de mudas que cada arvore produz por dia
    cin >> t >> m >> a;
    // T^M*D = A
    int dias = 0;

    while(1)
    {
        if(t >= a) break;
        t = t + t*m;
        dias++;

    }
    
    cout << dias << endl;


    return 0;
}