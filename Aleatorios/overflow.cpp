#include <iostream>

using namespace std;

int main(){
    int n,p,q;
    char c;
    cin >> n;
    cin >> p >> c >> q;
    switch (c)
    {
        case '+':
        if(p+q > n)
        cout << "OVERFLOW";
        else
        cout << "OK";
        break;
        case '*':
        if(p*q > n)
        cout << "OVERFLOW";
        else
        cout << "OK";
        break;
    }
    
    return 0;
}