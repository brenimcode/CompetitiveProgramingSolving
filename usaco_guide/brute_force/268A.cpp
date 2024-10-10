#include <bits/stdc++.h>

using namespace std;

#define NMAX 8
#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define int long long
#define pp pair<int, int>
int n;

int32_t main()
{
    cin >> n;
    vector<pp> vet;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vet.push_back({a, b});
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j) continue;
            if(vet[i].second == vet[j].first){
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}