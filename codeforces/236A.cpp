#include <bits/stdc++.h>

using namespace std;
#define int long long


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(cin,str);
    set<char> letras;
    for(auto letra : str) {
        letras.insert(letra);
    }

    if(letras.size()%2 == 0){
        cout << "CHAT WITH HER!" <<endl;
    }
    else{   //man
        cout << "IGNORE HIM!" <<endl;
    }

}
