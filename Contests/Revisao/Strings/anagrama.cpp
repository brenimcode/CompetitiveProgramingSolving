#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main()
{
    int i;
    
    string str,str2,aux,aux2;
    cin >> i;
    cin.ignore();
    getline(cin, aux);
    str = "";
    for (i = 0; i < (int) aux.size(); i++)
    {
        if((aux[i] >= 'a' && aux[i] <= 'z') || ( aux[i] >= 'A' && aux[i] <= 'Z')){
            str+=aux[i];
        }
    }
    

    getline(cin,aux2);
    str2 = "";
    for (i = 0; i < (int) aux2.size(); i++)
    {
        if((aux2[i] >= 'a' && aux2[i] <= 'z') || ( aux2[i] >= 'A' && aux2[i] <= 'Z')){
            str2+=aux2[i];
        }
    }

    sort(str.begin(),str.end());
    sort(str2.begin(),str2.end());

    if(str == str2) {
        cout << "S" << endl;
    }
    else{
        cout << "N" << endl;
    }
    

    return 0;
}