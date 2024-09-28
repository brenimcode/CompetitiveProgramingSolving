#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a;
    cin >> a;
    cin.ignore();
    string str;
    for(int i = 0;i<a;i++){
        char aux;
        cin >> aux;
        str += aux;
    }



    int ans = 0;

    for (int i = 1; i < (int) str.size(); i++)
    {
        if(str[i] == str[i-1]){
            ans++;
        }
    }
    
    cout << ans << endl;

}
