#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,a,b,c,d,e,f,g;
    cin >> n >> a >> b >> c >> d >> e >> f >> g;
    int tot = n - ((a-d-e)  + (b-d-f) + (c-e-f) + d + e + f + g);
    if(tot)
        cout << 'S';
    else
        cout << 'N';
}   