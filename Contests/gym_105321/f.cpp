#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main() {
    int n;

    cin >> n;
    int ans = 0;
    int vet[n];
    for(int i = 0; i < n; i++) {
        cin >> vet[i];
        if(i >= 2){
            if(vet[i-2] == vet[i-1] && vet[i] == vet[i-1] && vet[i] == 1){
                ans++;
            }
        }
        if(vet[i]){
            ans++;
        }
        else{
            ans--;
        }
    }
    cout << ans << endl;

    return 0;
}