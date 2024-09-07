#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " --->>> " << x << endl
#define int long long

int32_t main()
{

    string str;

    while (getline(cin, str))
    {
        bool ans = true;

        stack<int> pilha;
        int len = str.size();

        for(int i = 0; i < len ;i++) {
            if(str[i] == '(') {
                pilha.push(str[i]);
            }
            else if(str[i] == ')'){
                if(!pilha.empty()){
                    pilha.pop();
                }
                else{
                    ans = false;
                }
                
            }
            
        }
        if(!pilha.empty()){
            ans = false;
        }

        if (ans)
        {
            cout << "correct" << endl;
        }
        else
        {
            cout << "incorrect" << endl;
        }
    }

    return 0;
}