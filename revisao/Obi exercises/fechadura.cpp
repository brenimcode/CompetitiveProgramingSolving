#include <bits/stdc++.h>

using namespace std;

// Debug macro for printing variable values (optional, can be removed in production)
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main()
{
    int n, i, m;
    cin >> n >> m;
    int vet[n];
    for (i = 0; i < n; i++)
        cin >> vet[i];
    int sum = 0;
        for (i = 0; i < n; i++)
        {
            if(vet[i] != m){
                int dif = m - vet[i];
                sum += abs(dif);
                vet[i] += dif;
                vet[i+1] += dif;
            }
        }

    cout << sum << endl;

    return 0;
}
