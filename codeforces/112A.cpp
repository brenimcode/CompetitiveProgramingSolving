#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    int n;

    getline(cin, str1);
    getline(cin, str2);
    n = (int) str1.size();

    for (int i = 0; i < n; i++)
    {
        str1[i] =  tolower(str1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        str2[i] =  tolower(str2[i]);
    }

    if(str1 > str2) {
        cout << 1 << endl;
    }
    else if(str1 < str2) {
        cout << -1 << endl;
    }
    else{
        cout << 0 << endl;
    }

}
