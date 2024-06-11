#include <bits/stdc++.h>

using namespace std;

#define DEBUG(a) cout << #a << " >>>> " << a << endl;

int main(){
    string str;
    getline(cin,str);

    set<int> letras;
    for (int i = 0; i < (int) str.size(); i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z'){
            letras.insert(str[i]);
        }
    }
    


    if(letras.size() == 23){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }

    return 0;
}
