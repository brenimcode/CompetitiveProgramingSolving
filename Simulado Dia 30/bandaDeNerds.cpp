#include <bits/stdc++.h>

using namespace std;
#define par pair<int,string>

typedef struct tupla{
    int h;
    string ins;
    int qtd;
}tupla;

bool func(tupla a, tupla b){
    if(a.h != b.h)
        return a.h > b.h;
    return a.ins > b.ins;

}

int main(){
    int n,i,k,j;

    cin >> n >> k;
    vector<tupla> banda;

    for(i =0 ;i<n;i++){
        string a;
        int b;
        cin.ignore();
        cin >> a >> b;
        tupla t;
        t.h = b;
        t.ins = a;
        t.qtd = 0;
        banda.push_back(t);
    }
    sort(banda.begin(),banda.end(),func);
    /*
    for(i =0 ;i<n;i++){
        cout << "(" << banda[i].first << "," << banda[i].second << ")\n";
    }
    */

    int pontos = 0;
    for(i =0 ;i<n;i++){
        string bandaAtual = banda[i].ins;

        for(j =i ;j<n;j++){
            if(banda[j].qtd == k) break;
            if(bandaAtual == banda[j].ins && banda[j].ins != "-1"){
                banda[j].qtd++;
                printf("cont = (%d)\n",banda[j].qtd);
                cout << banda[j].ins << '-';
                printf("[%d]\n",banda[j].h);
                pontos+= banda[j].h;
                banda[j].ins = "-1";
            }

        }
    }
    cout << pontos << endl;

    return 0;
}
// deve 1, 4, deve :5 , devem para ele: 3