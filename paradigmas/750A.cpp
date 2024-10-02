#include <bits/stdc++.h>

using namespace std;

#define NMAX 8
#define DEBUG(x) cout << #x << " >>>> " << x << endl;

int main()
{
    int n, k, ans;
    cin >> n >> k;
    // 4h = 240min
    // k = minutos que ele precisa para ir a festa!
    ans = (240-k);
    // 18 o maximo que posso fazer!
    int sum = 0,i = 1;
    int qtd = 0;
    while(sum+(5*i) <= ans && qtd != n){
        sum += 5*i;
        i++;
        qtd++;
    }

    cout << qtd << endl;

    return 0;
}