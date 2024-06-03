#include <bits/stdc++.h>

using namespace std;

bool eh_primo(int x){
    if(x == 2 || x == 3 || x == 5){
        return true;
    }
    if(!x%2 || x == 1 || !x%3){
        return false;
    }

    int raiz = sqrt(x);
    for (int i = 2; i <= raiz; i++)
    {
        if(x%i == 0){
            return false;
        }
    }
    
    return true;
}

int main()
{

    int n;
    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;

        if (eh_primo(x))
        {
            cout << x << " eh primo" << endl;
        }
        else
        {
            cout << x << " nao eh primo" << endl;
        }
    }

}