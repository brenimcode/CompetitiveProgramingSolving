#include <bits/stdc++.h>

using namespace std;

// Debug macro for printing variable values (optional, can be removed in production)
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main() {
    int n,s;

    cin >> n >> s;
    int aux;
    int menor = s;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        s += aux;
        if(menor > s){
            menor = s;
        }
    }
    
    cout << menor << endl;
    
    return 0;
}
