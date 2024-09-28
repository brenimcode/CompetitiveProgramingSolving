#include <bits/stdc++.h>

using namespace std;
#define int long long


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n; 
    cin.ignore();
    int x = 0;
    while(n--) {
        string str;
        getline(cin,str);

        if(str[0] == '+' || str[2] == '+'){
            x++;
        }else{
            x--;
        }
    }    
    cout << x << endl;

}
