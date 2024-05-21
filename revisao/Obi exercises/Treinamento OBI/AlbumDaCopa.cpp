#include <bits/stdc++.h>

using namespace std;

// Debug macro for printing variable values (optional, can be removed in production)
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main()
{
    int n, i, m,aux;
    cin >> n >> m;
    set<int> vet;
    for (i = 0; i < m; i++){
        cin >> aux;
        vet.insert(aux);
    }

    cout << n - vet.size()<< endl;

    return 0;
}
