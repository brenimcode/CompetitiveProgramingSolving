#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,ans;
    cin >> a;
    if((a%5) == 0){
        ans = a/5;
    }
    else{
        ans = ceil(a/5)+1;
    }

    cout << ans << endl;

}
