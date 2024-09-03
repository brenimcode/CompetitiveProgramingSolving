#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " --->>> " << x << endl
#define NMAX 105


int32_t main() {
    int n;
    cin >> n; // n == numero de diretor, k = duração maxima
    int a,b;
    for(int i = 1; i <= n;i++) {
        cin >> a >> b;
        cout << b-a << endl;
    }
    
    return 0;
}
