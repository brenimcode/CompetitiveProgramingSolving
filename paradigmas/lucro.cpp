#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " --->>> " << x << endl

int32_t main() {
    int n, cost;

    // Reading n = number of days, cost = daily cost
    while (cin >> n >> cost) {
        vector<int> vet(n);
        for (int i = 0; i < n; i++) {
            cin >> vet[i];
            vet[i] -= cost;  // Subtracting the cost of one day from each element
        }

        int sum = 0, best = LLONG_MIN;
        int current_days = 0, max_days = 0;

        for (int i = 0; i < n; i++) {
            if (sum + vet[i] > vet[i]) {
                sum += vet[i];
                current_days++;
            } else {
                sum = vet[i];
                current_days = 1; // restart the count
            }

            if (sum > best) {
                best = sum;
                max_days = current_days; // update max_days when we find a new best
            }
        }

        int ans = best;  // The cost has already been subtracted from the sequence
        ans = max(0LL,ans);
        cout << ans << endl;

    }

    return 0;
}
