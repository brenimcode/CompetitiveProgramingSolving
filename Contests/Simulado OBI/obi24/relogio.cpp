#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);


int32_t main() {
    _
   int h,m,s,t;
   cin >> h >> m >>s >>t ;
    // h = [0,23]
    int segundos = (s+t)%60;
    int minutos = (m + ((s+t)/60) )% 60;
    int mins = (m + ((s+t)/60) )/ 60;
    int horas = (h + mins )% 24;

    cout << horas << endl;
    cout << minutos << endl;
    cout << segundos << endl;

    return 0;
}
