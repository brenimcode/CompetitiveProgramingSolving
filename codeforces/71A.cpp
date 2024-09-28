#include <bits/stdc++.h>

using namespace std;
#define int long long


int32_t main() {
    int n;
    string str;

    cin >> n; 
    cin.ignore();
    while(n--) {
        getline(cin,str);
        if(str.size() > 10){
            cout << str[0];
            cout << str.size()- 2;
            cout << str[str.size()-1];
        }else{
            cout << str;
        }
        cout << endl;
    }    

}
