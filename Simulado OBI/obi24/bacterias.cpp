#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);


int32_t main() {
    _
   int n,p;
   cin >> n >> p;
   int qtd = 1;
   int dias = 0;
   while(qtd <= n){
    qtd = qtd*p;
    if(qtd > n){
        break;
    }
    dias++;

   }
    cout << dias << endl;
    return 0;
}
