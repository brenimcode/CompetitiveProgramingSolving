#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    if((a == d && b == c) || (a != d && b != c)){
        cout << -1 << endl;
    }else if(a != d && b == c){
        cout << 1 << endl;
    }
    else{
        cout << 2 << endl;
    }


}
