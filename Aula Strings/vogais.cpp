#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;

int main() {
    string str;
    cin >> str;

    vector<char> vogais; // vetor para armazenar todas as vogais
    vector<char> consoantes;

    for (int i = 0; i <(int) str.size(); i++)
    {
        if(str[i] == 'a' ||str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ){
            vogais.push_back(str[i]);
        }
        else{
            consoantes.push_back(str[i]);
        }
    }
    cout << "Vogais: ";
    for (int i = 0; i < (int) vogais.size(); i++)
    {
        cout << vogais[i];
    }
    cout << endl;
    cout << "Consoantes: ";
     for (int i = 0; i <(int) consoantes.size(); i++)
    {
        cout << consoantes[i];
    }
    cout << endl;

}
