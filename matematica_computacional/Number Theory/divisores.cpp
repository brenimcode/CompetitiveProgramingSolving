#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int sqrt_c = sqrt(c);
    int result = -1;

    // Procurando por divisores de C
    for (int i = a; i <= sqrt_c; i+=a) {

        if (c%i == 0) {
            int div = c / i;
            // Checar div1
            if (i%b != 0 && d%i != 0) {
                if (result == -1 || i < result) {
                    result = i;
                }
            }

            // Checar div
            if (div%a == 0 && div%b != 0 && d%div != 0) {
                if (result == -1 || div < result) {
                    result = div;
                }
            }
        }
    }

    cout << result << endl;
    return 0;
}
