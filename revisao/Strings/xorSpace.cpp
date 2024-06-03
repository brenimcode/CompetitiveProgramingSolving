#include <bits/stdc++.h>

#define DEBUG(x) cout << #x << " >>>> " << x << endl

using namespace std;

string xorSpace(string s){
     int n=s.size();
     for (int i=0; i<n; ++i){
            s[i]^=' ';
     }
     return s;
}

int main() {
    string str;
    getline(cin,str);

    cout << xorSpace(str) << endl;
    
    return 0;
}
