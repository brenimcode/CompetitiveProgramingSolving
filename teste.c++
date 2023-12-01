#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    if(y > z)
        cout << y-z << endl;
    else if(y < z){
        cout << y+x-z << endl;
    }
    else{
        cout << 0;
    }
    return 0;
}
