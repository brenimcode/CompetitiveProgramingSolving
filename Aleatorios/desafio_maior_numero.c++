#include <bits/stdc++.h>

using namespace std;

int main(){
    set <int> a;
    int x;
    while(1)
    {
        cin >> x;
        if(x == 0)
            break;
        a.insert(x);
    }
        cout << *a.rbegin() << endl;
        //acessar o maior elemento
    return 0;
}
