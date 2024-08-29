#include <bits/stdc++.h>

using namespace std;

// Debug macro for printing variable values (optional, can be removed in production)
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main()
{
    int n;
    cin >> n;
    int result = n - 9;
    if(result < 0){
        result+=24;
    }
    cout << result << endl;

    return 0;
}
