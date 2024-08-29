#include <bits/stdc++.h>

using namespace std;

// Debug macro for printing variable values (optional, can be removed in production)
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main()
{
    int v,p;
    cin >> v >> p;
    int res = v%p;
    int quo = v/p;

    for (int i = 0; i <res; i++)
    {
        cout << quo+1 << endl;
    }
    
        for (int i = 0; i < p-res; i++)
        {
            cout << quo << endl;
        }

    return 0;
}
