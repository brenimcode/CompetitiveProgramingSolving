#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    
    int a,b,c;
    cin >> a >> b >> c;
    bool ver = false;

    if(a+b <=c  || a+c <=b  || b+c <= a ){
        ver = true;
    }

    if(ver){
        cout << 'S' << endl;
    }
    else{
        cout << 'N' << endl;
    }

    return 0;
}
