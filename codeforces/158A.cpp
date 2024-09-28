#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;
    int ans = 0;
    int vet[n];
    int kesimo_lugar = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
        if(i == k-1){
            kesimo_lugar = vet[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(vet[i] >= kesimo_lugar && vet[i] > 0){
            ans++;
        }else{
            break;
        }
    }



    cout << ans << endl;
}
