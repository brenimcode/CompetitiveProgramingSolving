#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int32_t main()
{
    _
    string str;
    getline(cin, str);
    
    bool ver = true;
    
    // primeira condição
    for (int i = 0;i <3; i++)
    {
        if(!(str[i] >= 'A' && str[i]<='Z')){
            ver = false;
            break;
        }
    }

    //segunda condição
    if(str[3] == '-'){
        // Brasil
        
        int n = str.size();
        for (int i = n-1; i >= n-4; i--)
        {
            if(!isdigit(str[i])){
                ver = false;
                break;
            }
        }
        
        if(ver){
            cout << 1 << endl;
        }


    }else if(isdigit(str[3])){
        // mercosul
        if(!(str[4] >= 'A' && str[4]<='Z')){
            ver = false;
        }

        int n = str.size();
        for (int i = n-1; i >= n-2; i--)
        {
            if(!isdigit(str[i])){
                ver = false;
                break;
            }   
        }

        if(ver){
            cout << 2 << endl;
        }

    }else{
        ver = false;
    }


    if(!ver){
        cout << 0 << endl;
    }
    

    return 0;
}
