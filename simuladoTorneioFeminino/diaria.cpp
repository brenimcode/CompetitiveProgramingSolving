#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define NMAX 105
#define KMAX 100010
#define int long long

int n,k,p,q;
int diarias[KMAX];
int somas[KMAX];

int32_t main()
{
    cin >> n;

    int seq = 1;
    int limite = 0;
    somas[0] = 0; somas[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> k >> p;
        // k dias consecutivos valerao P
        limite +=k;
        for (int j = seq; j <= limite; j++)
        {
            diarias[j] = p;
            somas[j] = somas[j-1] + diarias[j];

        }
        seq+=k;
        
    }

    cin >> q;


    for (int i = 0; i < q; i++)
    {
        int x,y;
        cin >> x >> y;
        
        int sum = somas[y]-somas[x-1];
        
        cout << sum << endl;
        
    }


}