#include <bits/stdc++.h>

using namespace std;

int main(){
    string a;
    string b;
    getline(cin,a);
    getline(cin,b);
    string result= "";
    int i;

    for (i = 0; i <(int) b.size(); i++)
    {
        result+='a'+a.find(b[i]);
    }
    cout << result;
    
}