#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " --->>> " << x << endl
#define NMAX 105


int dp[NMAX];


int fib(int n) {
    if(dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);
}


int32_t main() {
    int n;
    cin >> n; // n == numero de diretor, k = duração maxima
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n;i++) {
        dp[i] = -1;
    }

    cout << fib(n) << endl;
    
    return 0;
}
