/*
beecrowd | 1103

*/
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main()
{

    int n;

    while (cin >> n)
    {
        if (n == 0)
            break; // Termination case
        int aux;    
        int john = 0;
        for(int i =0;i < n;i++) {
            cin >> aux;
            if(aux == 1){
                john++;
            }
        }

        cout << "Mary won " << n-john << " times and John won " << john << " times" << endl;
    }

    return 0;
}
