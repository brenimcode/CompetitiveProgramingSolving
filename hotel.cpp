#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,d,n,mult;
    cin >> d >> a >> n;
    
    int sub = 32-n;//31 dias
    if(n < 16)
        mult = n-1;
    else
        mult = 14;
    cout << sub*(d+(mult*a));

    return 0;
}
