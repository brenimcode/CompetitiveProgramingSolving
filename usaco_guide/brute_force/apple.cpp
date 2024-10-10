#include <bits/stdc++.h>

using namespace std;

#define NMAX 8
#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define int long long
int n;

int32_t main()
{
    cin >> n;
    vector<int> apples;
    apples.resize(n);
    for (auto &i : apples)
    {
        cin >> i;
    }


    int ans = INT64_MIN;
    for(int b = 0 ;b< (1<<n) ;b++){
        int s1 = 0, s2 = 0;

        for(int i = 0;i < n;i++){
            // ve se o iésimo-BIT de B é 1.
            if(b & (1 << i)){
                // se for 1, coloca na s1, se nao coloca na s2.
                s1 += apples[i];
            }
            else{
                s2 += apples[i];
            }
        }
        ans = min(ans, abs(s1-s2));
    }

    cout << ans << endl;

    return 0;
}