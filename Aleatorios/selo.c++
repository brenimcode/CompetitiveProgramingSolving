#include <bits/stdc++.h>

using namespace std;

bool eh_primo(int x){
    if(x%2 == 0 || x%3 == 0){
        return false;
    }
    int i;
    for (i = 5; i*i <= x; i+=2)
    {
        if(x%i == 0)
            return false;
    }
    return true;
}

int main(){
    int x;
    cin >> x;
    if(x < 4 || (eh_primo(x)))
        cout << 'N';
    else
        cout << 'S';
}