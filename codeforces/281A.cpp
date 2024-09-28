#include <bits/stdc++.h>

using namespace std;
#define int long long


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(cin,str);
    if(str[0] >= 'a' && str[0] <= 'z') str[0] += 'A'-'a'; 

    cout << str << endl;
}
