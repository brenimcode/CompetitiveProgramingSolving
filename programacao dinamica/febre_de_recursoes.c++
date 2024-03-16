#include <bits/stdc++.h>

using namespace std;

int n=2,k,m;
int  base_f[1001];
int a[1001];

int  febre(int kl){
        if(base_f[kl] != -1)
            return base_f[kl];
    
        base_f[kl] = 0;
        
        for (int i = 1; i <= n ; i++)
        {
            if(kl >= i)
                base_f[kl] = (base_f[kl] + 1LL * a[i] * febre(kl - i)) % m;
        }
        
        return base_f[kl];
    
}


int main()
{   
    cin >> n >> k >> m;
    int i;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];    
    }

    for (i = 1; i <= n; i++)
    {
        cin >> base_f[i];
    }

    for (i = n+1; i <= k; i++)
    {
        base_f[i] = -1;
        
    }

    cout << febre(k)%m << endl;

    return 0;
}