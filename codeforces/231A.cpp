#include <bits/stdc++.h>

using namespace std;
#define int long long


int32_t main() {
    int n;

    cin >> n; 
    int a,b,c,ans = 0;
    while(n--) {
        cin >> a >> b >> c;
        if(a+b+c >= 2){
            ans++;
        }
    }    
    cout << ans << endl;

}
