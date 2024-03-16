
#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b){
  return (b == 0 ? a : mdc(b, a%b)); //b == 0 ? Caso sim, retorne a, caso não, retorne mdc(b, a%b)
}

int main(){
    int x,i,aux,res;
    cin >> x;
    vector <int> vet;
    for (i = 0; i < x; i++)
    {
        cin >> aux;
        vet.push_back(aux);
    }
    while( (int) vet.size() != 1)
    {
            res = mdc(vet[1],vet[0]);
            vet.erase(vet.begin());
            vet.erase(vet.begin());
            vet.push_back(res);
    }
    cout << vet[0] << endl;
    

}

