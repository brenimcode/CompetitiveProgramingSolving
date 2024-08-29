#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int32_t main() {
    int n,q;

    cin >> n >> q;

    int vet[n+2];
    vet[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> vet[i];
    }

    int sums[n+2];
    sums[0] = 0;
    sums[1] = vet[1];
    for (int i = 2; i <= n; i++)
    {
        sums[i] = sums[i-1] + vet[i];
    }

    for (int i = 0; i < q; i++)
    {
        int a,b;
        cin >> a >> b;
        printf("%lld\n", sums[b] - sums[a-1]);

    }
    

    
    

}