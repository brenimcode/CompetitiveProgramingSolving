#include <bits/stdc++.h>

using namespace std;

int main(){
    int d;
    cin >> d;
    d -= 5;
    if(d%8 == 1)
        cout << 1;
    else if(d%8 == 2)
        cout << 2;
    else 
        cout << 3;

    
}   