#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);


    int valP,valD, habP, habD, n;
    cin >> valP >> habP;
    cin >> valD >> habD;
    cin >> n;
    int ansP = 0,ansD = 0;
    while(n--){
        int a,b;
        cin >> a >> b;
        if(habP >= a && habD >= b){
            ansP+=valP;
            ansD += valD;
        }

    }

    cout << "Programador: R$ " <<ansP << endl;
    cout << "Designer: R$ " << ansD << endl;

    return 0;
}