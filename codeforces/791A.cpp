#include <bits/stdc++.h>

using namespace std;
#define int long long


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,ans = 0;
    cin >> a >> b;
    // y peso, x idade
    while(1){
        a = 3*a;
        b = 2*b;
        ans++;
        if(a > b) break;
    }

    cout << ans << endl;

}
