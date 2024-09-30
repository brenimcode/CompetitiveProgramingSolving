#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(cin,str);
    int n = (int) str.size();
    int contador = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == '7' || str[i] == '4'){
            contador++;
        }
    }

    if(contador == 7 || contador == 4){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}
