#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " --->>> " << x << endl
#define int long long

int32_t main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    while (n--)
    {
        string str;
        getline(cin, str);
        stack<int> pilha;
        int len = str.size();
        int cont = 0;
        for(int i = 0; i < len ;i++) {
            if(str[i] == '<') {
                pilha.push(str[i]);
            }
            else if(str[i] == '>'){
                if(!pilha.empty()){
                    pilha.pop();
                    cont++;
                }
            }
            
        }
        

        
        cout << cont << endl;
    }

    return 0;
}