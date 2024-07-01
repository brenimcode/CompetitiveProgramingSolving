#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);


int32_t main() {
    _
   int n,k;
   cin >> n >> k;
   priority_queue<int> fila;
   for (int i = 0; i < n; i++)
   {
    int aux;
     cin >> aux;
     fila.push(aux);
   }
   while(--k){
    fila.pop();
   }
   
   cout << fila.top() << endl;
   
    return 0;
}
