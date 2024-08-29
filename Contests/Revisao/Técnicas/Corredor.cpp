#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int32_t main() {
    _
    int n;
    cin >> n;
    int vet[n];

    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }

    int sum = vet[0];
    int best = sum;

    for (int i = 1; i < n; i++)
    {
        sum = max(sum+vet[i],vet[i]); // Eu começo uma nova sequencia ou eu continuo?
        best = max(sum,best);
    }

    cout << best << endl;
        

    return 0;
}
