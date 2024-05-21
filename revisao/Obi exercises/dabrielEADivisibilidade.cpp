#include <bits/stdc++.h>

using namespace std;

// Debug macro for printing variable values (optional, can be removed in production)
#define DEBUG(x) cout << #x << " >>>> " << x << endl
int main()
{
    int m;
    string n;
    getline(cin, n);
    cin >> m;
    int vet[m];
    for (int i = 0; i < m; i++)
    {
        cin >> vet[i];
    }
    int num = 0;

    for (int i = 0; i < (int) n.size(); i++)
    {
        num = num*2 + (n[i]-'0');
    }

    bool ver = 0;
    sort(vet, vet + m);
    for (int i = 0; i < m; i++)
    {
        if (num % vet[i] == 0)
        {
            cout << vet[i] << ' ';
            ver = 1;
        }
    }
    if (!ver)
    {
        cout << "Nenhum\n";
    }

    return 0;
}