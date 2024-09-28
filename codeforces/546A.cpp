#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k,n,w;
    cin >> k >> n >> w;
    // Ele tem N dolares, quer W bananas, porém, temos que cada banana começa com K
    // K, 2K, 3K, 4K, 5KÇ. 
    int ans = n- (w*k+k)*w/2;
    if(ans < 0) ans *= -1;
    else if(ans > 0) ans = 0;

    cout << ans << endl;

}
