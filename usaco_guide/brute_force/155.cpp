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
    vector<int> vet(n);
    for (int &i : vet)
    {
        cin >> i;
    }

    int ans = 0;
    vector<int> maiores(n);
    vector<int> menores(n);
    maiores[0] = vet[0];
    menores[0] = vet[0];
    for (int i = 1; i < n; i++)
    {
        maiores[i] = max(vet[i], maiores[i-1]);
        menores[i] = min(vet[i], menores[i-1]);
    }




    for (int i = 1; i < n; i++)
    {   
        if(vet[i] > maiores[i-1] || vet[i] < menores[i-1]){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}