#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,init,p;

    cin >> n >> init >> p;

    for (int i = 0; i < p; i++)
    {
        
        init++;
        if(init > n) init = 1;    
    }
    
    cout << init << endl;

}