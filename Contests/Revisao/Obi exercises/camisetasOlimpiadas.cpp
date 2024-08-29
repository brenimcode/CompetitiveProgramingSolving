#include <bits/stdc++.h>

using namespace std;

// Debug macro for printing variable values (optional, can be removed in production)
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main() {
    int n;

    cin >> n;
    int P=0,M=0,x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if(x == 1) P++;
        else M++;
     }
    int a,b;
     cin >> a >> b;
     if(a <= P && b <= M) {
        cout << "S" << endl;
     }
     else{
        cout << "N" << endl;
     }




    

    return 0;
}
