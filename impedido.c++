#include <bits/stdc++.h>

using namespace std;

int main(){
    int l,r,d;
    cin >> l >> r >> d;
    if(r > 50 && l < r && r>d)
        cout << 'S';
    else 
        cout << 'N';
}   