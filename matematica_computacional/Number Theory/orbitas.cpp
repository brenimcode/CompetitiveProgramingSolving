#include <bits/stdc++.h>

using namespace std;
#define int long long


int mdc(int a, int b){
    if(b == 0) return a;
    return mdc(b,a%b);
}

int mmc(int a,int b){
    return (a*b)/mdc(a,b);
}


int32_t main(){
    int a,b;
    cin >> a >> b;

    cout << mmc(a,b) << endl;
    
}