#include <bits/stdc++.h>

using namespace std;


int main(){
    string str;
    getline(cin,str);
    istringstream nome (str);
    vector<int> subs;
    int numero;
    while(nome >> numero){
        subs.push_back(numero);
    }
    sort(subs.begin(),subs.end());
    for(auto&aux : subs){
        if(1 == aux){
            cout << "A ";
        }
        else if(11 == aux){
            cout << "J ";
        }
        else if(12 == aux){
            cout << "Q ";
        }
        else if(13 == aux){
            cout << "K ";
        }
        else{
            cout << aux << ' ';
        }

    }
    return 0;

}
