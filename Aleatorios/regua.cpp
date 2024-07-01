#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k,x,y;
    cin >> k >> x >> y;

    if(abs(y-x) >= k)
        cout << "EH SUFICIENTE" << endl;
    else
        cout << "NAO EH SUFICIENTE" << endl;
    
    
    return 0;
}
