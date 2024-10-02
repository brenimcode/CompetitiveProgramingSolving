#include <bits/stdc++.h>

using namespace std;

#define NMAX 8
#define DEBUG(x) cout << #x << " >>>> " << x << endl;

int main()
{
    int r1,r2,c1,c2;
    cin >> r1 >> c1 >> r2 >> c2;

    if(r1 == r2 && c1 == c2){
        cout << 0 << ' ';
    }else if(r1 == r2 || c1 == c2){
        cout << 1 << ' ';
    }else{
        cout << 2 << ' ';
    }

    if((r1 == r2 && c1 == c2) || ((c1+r1)%2 != (c2+r2)%2)){
        cout << 0 << ' ';
    }
    else if((r1-c1) == (r2-c2) || (r1+c1) == (r2+c2)){
        cout << 1 << ' ';
    }
    else{
        cout << 2 << ' ';
    }

    cout << max(abs(r1 - r2), abs(c2 - c1)) << endl;

    return 0;
}