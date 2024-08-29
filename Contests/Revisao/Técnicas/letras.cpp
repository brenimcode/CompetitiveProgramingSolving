#include <bits/stdc++.h>

using namespace std;

#define DEBUG(a) cout << #a << " >>>> " << a << endl;
#define PB push_back

vector <char> pilha;
int n;

int main(){
    string str;
    getline(cin,str);
    n = str.size();
    for (int i = 0; str[i] != str[n]; i++)
    {
        char x = str[i];

        vector<char>::iterator it = upper_bound(pilha.begin(),pilha.end(), x); // Retorna o 1° Cara > x
        if(it == pilha.end()){
            pilha.push_back(x);
        }
        else{
            *it = x; // cara que estou apontando 'recebe' x
        }

    }

    cout << pilha.size() << endl;    

}
