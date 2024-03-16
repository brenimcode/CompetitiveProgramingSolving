#include <bits/stdc++.h>

using namespace std;

int main(){
    bool ia,ib,fa,fb;
    cin >> ia >> ib >> fa >> fb;
    if(ia != fa && ib != fb)
        cout << 1;
    else if(fa == ia && fb!=ib)
        cout << 2;
    else if(fa!=ia && fb==ib)
        cout << 1;
    else if(fa==ia && fb==ib)
        cout << 0;

  
}   