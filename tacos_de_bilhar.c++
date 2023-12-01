#include <bits/stdc++.h>

using namespace std;

int main(){
    int q,i,temp,cont=0;
    set <int> estoque;
    cin >> q;
    for (i = 0; i < q; i++)
    {
        cin >> temp;
        if(estoque.find(temp) != estoque.end()){ //ele esta no estoque!
            estoque.erase(temp);
            continue;
        }
        estoque.insert(temp);
        cont+=2;
    }
    cout << cont << endl;

}