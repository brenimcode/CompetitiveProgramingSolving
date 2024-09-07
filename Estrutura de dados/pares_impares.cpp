#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " --->>> " << x << endl
#define int long long

int32_t main()
{
    
    int n; // 1 a 50
    cin >> n;
    int num;
    priority_queue<int> impares; // maior no topo
    priority_queue<int, vector<int>, greater<int> > pares; // Menor no topo
    while (n--)
    {
        
        cin >> num;
        if(num%2 == 0) {
            pares.push(num);
        }
        else{
            impares.push(num);
        }
    }

    while(!pares.empty()){
        int topo = pares.top();
        pares.pop();
        cout << topo << endl;
    }

    while(!impares.empty()){
        int topo = impares.top();
        impares.pop();
        cout << topo << endl;
    }

    return 0;
}