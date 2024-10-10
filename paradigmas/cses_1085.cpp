#include <bits/stdc++.h>

using namespace std;

#define NMAX 8
#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define int long long

int32_t main()
{
    int n, k;

    cin >> n >> k;
    vector<int> vet(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    sort(vet.begin(), vet.end());
    cout << "\n-----------\n";

    for (int i = 0; i < n; i++)
    {
        cout << vet[i] << ' ';
    }
    cout << endl;

    return 0;
}