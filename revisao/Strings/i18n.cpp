#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main()
{
    int i;
    string str;
    getline(cin, str);
    int n = str.size();
    cout << str[0];
    int sum=0;
    for (i = 1; i < n-1; i++)
    {
        sum++;
    }
    cout << sum;
    cout << str[n-1];
    

    return 0;
}