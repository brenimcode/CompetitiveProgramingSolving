#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);


int32_t main() {
    _
    int e,d;
    cin >> e >> d;
    if(e > d){
        cout << e+d << endl;
    }
    else{
        cout << 2*(d-e) << endl;
    }
    
    return 0;
}
