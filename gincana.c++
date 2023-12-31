#include <bits/stdc++.h>

using namespace std;

long long mdc(long long a, long long b){
  return (b == 0 ? a : mdc(b, a%b)); //b == 0 ? Caso sim, retorne a, caso não, retorne mdc(b, a%b)
}


int main()
{
    long long n,m,i;
    cin >> n >> m;

    for (i = 0; i < m ; i++)
    {
        //achar o mdc de (a,b) tal que b seja o maior possivel
        if(mdc(n,m) == 1){
            cout << m;
            return 0;
        }
        m--;

    }
    cout << m;

}