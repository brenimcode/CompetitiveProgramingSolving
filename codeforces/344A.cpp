#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int vet[n], grupos;
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }

    grupos = 1;
    for (int i = 1; i < n; i++)
    {
        if(vet[i] != vet[i-1]){
            grupos++;
        }
    }

    cout << grupos << endl;
}