#include <bits/stdc++.h>

using namespace std;
#define INF 1000000109
#define int long long

int32_t main() {
    int n,x;

    cin >> n >> x;
    int vet[n+1];

    for (int i = 1; i <= n; i++)
    {
        cin >> vet[i];
    }
    
    unordered_map <int,int> prefixSomas;
    prefixSomas[0] = 1; // SOMA zero OCORRE 1 Vez

    int sum = 0;
    int currentSum = 0;

    for (int num : vet){
        currentSum = num;
        //verifica se a CurrentSum - X, já ocorreu: (j > i) currentSum = prefix[j],  prefix[j] - prefix[i] = k, [x1,x2,K] - [x1,x2] = K 
        if (prefixSomas.find(currentSum - x) != prefixSomas.end()) {
            sum += prefixSomas[currentSum - x];
        }
        // Atualiza o mapa com a nova soma acumulada.
        prefixSomas[currentSum]++;

    }
    

    cout << sum << endl;



    return 0;
}