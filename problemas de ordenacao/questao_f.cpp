#include <bits/stdc++.h>

using namespace std;

bool compara(pair<string,int> p,pair<string,int> p2){
    if(p.second != p2.second){
        return p.second > p2.second;
    }
    return p.first < p2.first;
}

int main(){
    int n,i,j;
    cin >> n;
    cin.ignore();
    pair <string,int> par[n];
    int num;
    for (i = 0; i < n; i++)
    {
        string str;
        getline(cin,str);
        string aux = ""; //Esse vai ser o "numero"
        int pos = str.find(','); //onde começa o , é a ultima posicao do nome, e ',' + 1 é onde começa o "NUMERO"
        for (j = pos+1; j <(int) str.size() ; j++)
        {
            aux+=str[j];
        }
        //leu um numero em forma de stirng
        istringstream ler (aux);
        ler >> num;
        
        string temp=""; //esse vai ser o nome
        for (j = 0; j < pos; j++)
        {
            temp+=str[j];
        }

        par[i] = make_pair(temp,num);
    }

    sort(par,par + n,compara);

    for (i = 0; i < n; i++)
    {
        cout << par[i].first << endl;
    }
    
    
    return 0;
}
