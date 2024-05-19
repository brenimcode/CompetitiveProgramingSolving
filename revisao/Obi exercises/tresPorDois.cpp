#include <bits/stdc++.h>

using namespace std;

// Debug macro for printing variable values (optional, can be removed in production)
#define DEBUG(x) cout << #x << " >>>> " << x << endl

bool funcao(int a,int b) {
    return a > b;
}

int main() {
    int n;

    cin >> n;
    int vet[n+1]; // Leva 3, pague os 2 mais caros, e o outro Gratis
    //8, 5, 10, 2, 5, 10,4 : (10,5,2) (8,5,4) (2)
    // ,5,,2,5,,4: (10,10,8) (5,5,4) (2)
    for (int i = 1; i <= n; i++){
            cin >> vet[i];
    }
    sort(vet+1,vet + n+1,funcao);

    int sum=0;
    for (int i = 1; i <= n; i++)
    {
        // elementos em (i) * 2, remover
        if(i%3!=0) sum+= vet[i];
    }

   
    
    cout << sum;

    return 0;
}
