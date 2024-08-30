/*
Carnaval - OBI 2012 - Segunda Fase
*/

#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl;
#define int long long

// Trans
int32_t main()
{
    double a;
    int n = 5;
    priority_queue<double> nums;
    while (n--)
    {
        cin >> a;
        nums.push(a);
    }
    double sum = 0;

    int it = 0;
    while (!nums.empty()) {

        if(it != 0 && it != 4) // ultimo e primeiro  n conta
            sum += nums.top(); // Pega elemento do topo
        it++;
        nums.pop(); // Remove o maior valor
    }


    printf("%.1f\n",sum);

    return 0;
}
