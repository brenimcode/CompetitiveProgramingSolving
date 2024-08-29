#include <bits/stdc++.h>

using namespace std;

#define DEBUG(a) cout << #a << " >>>> " << a << endl;

int main(){
    string str;
    int n;
    cin >> n;
    cin.ignore();
    getline(cin,str);
    int maior = 0;
    for (int i = 0; i < n; i++)
    {
        string sub = "";
        for (int j = i; j < n; j++)
        {
            sub+=str[j];
            string subR = sub;
            // Ordena as duas
            reverse(subR.begin(), subR.end());
            if(sub == subR){
                if((int) sub.size() > maior)
                    maior = sub.size();
            }
        }
        
    }
    
    cout << maior << endl;


    return 0;
}
