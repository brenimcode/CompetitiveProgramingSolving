#include <bits/stdc++.h>

using namespace std;

int main(){
    int i,n,m;
    char time = 'A';
    vector <char> vencedores;
    for (i = 0; i < 8; i++)
    {
        cin >> n >> m;
        if(n > m){
            vencedores.push_back(time);
        }
        else{
            vencedores.push_back(time+1);
        }
        time+=2;
    }

    for (i = 0; i < 4; i++)
    {
        cin >> n >> m;
        if(n > m){
            vencedores.erase(vencedores.begin()+i+1);
        }
        else{
            vencedores.erase(vencedores.begin()+i);
        }

    }

    for (i = 0; i < 2; i++)
    {
        cin >> n >> m;
        if(n > m){
            vencedores.erase(vencedores.begin()+i+1);
        }
        else{
            vencedores.erase(vencedores.begin()+i);
        }

    }
        cin >> n >> m;
        if(n > m){
            vencedores.erase(vencedores.begin()+1);
        }
        else{
            vencedores.erase(vencedores.begin());
        }
    cout << vencedores[0] << endl;
}