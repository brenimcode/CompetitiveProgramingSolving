#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int maior = 0;
    string nomeMaior = "";
    cin.ignore(); // inteiro -> string, ignora caracter
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin,str);
        int v;
        scanf("%d", &v);
        if(maior < v){
            maior = v;
            nomeMaior = str;
        }
        cin.ignore();

    }
    

    cout << nomeMaior << "\n" << maior << "\n";

}
