#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);


int32_t main() {
    _
    int n;
    cin >> n;
    string str1,str2;
    while(n--){
        cin >>str1 >> str2;
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        // str2 > str1 boa boas - abo abo
        char letraExtra = '.';
        for (int i = 0; i < (int) str2.size(); i++)
        {
            char atual = str2[i];
            for (int j = 0; j < (int) str1.size(); j++)
            {
                if(atual == str1){
                    
                }
            }
            
        }

        if(letraExtra == '.'){
            letraExtra = str2[str2.size()-1];
        }

        cout << letraExtra << endl;
        
    }
   
    return 0;
}
