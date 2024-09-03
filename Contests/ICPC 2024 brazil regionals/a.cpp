#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " --->>> " << x << endl

int32_t main() {
    int n, k;
    cin >> n >> k; // n == numero de diretor, k = duração maxima

    int quo = k/n;
    int ans = (quo*n) + (n-1);
    if(ans > k) quo--;

    cout << quo << endl;
    

    return 0;
}
