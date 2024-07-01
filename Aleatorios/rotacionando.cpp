#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);


    double x, y, tetha;
    cin >> x >> y >> tetha;

    cout << x*cos(tetha) - y*sin(tetha) << ' ';
    cout << x*sin(tetha) + y*cos(tetha) << endl;

    //x' = x*cos(tetha) - y*sin(tetha)  <-> y' = x*sin(tetha) + y*cos(tetha)

    return 0;
}