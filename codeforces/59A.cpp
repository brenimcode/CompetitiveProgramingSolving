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

    int maiu = 0, minu =0;
    for(int i = 0;i < (int) str.size(); i++){
        if(str[i] >= 'a' && str[i] <='z'){
            minu++;
        }
        else if(str[i] >= 'A' && str[i] <='Z'){
            maiu++;
        }
    }

    if(maiu > minu){
        for(int i = 0;i < (int) str.size(); i++){
            if(str[i] >= 'a' && str[i] <='z'){
                str[i]+='A'-'a';
            }
        }
    }
    else{
        for(int i = 0;i < (int) str.size(); i++){
            if(str[i] >= 'A' && str[i] <='Z'){
                str[i]= str[i] + ('a'-'A');
            }
        }
    }
    

    cout << str << endl;

}
