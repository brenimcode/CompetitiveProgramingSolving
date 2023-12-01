#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, i, x, cont = 0;
    set<int> alice;
    set<int> beatriz;
    cin >> a >> b;
    for (i = 0; i < a; i++)
    {
        cin >> x;
        alice.insert(x);
    }
    for (i = 0; i < b; i++)
    {
        cin >> x;
        beatriz.insert(x);
    }
    a = alice.size();
    b = beatriz.size();
    set<int>::iterator it;
    if (a < b)
    {
        for (it = alice.begin(); it != alice.end(); it++)
        {
            if (beatriz.find(*it) == beatriz.end()) // Verifico se o 5 está no meu set
                cont++;
        }
    }
    else
    {
        for (it = beatriz.begin(); it != beatriz.end(); it++)
        {
            if (alice.find(*it) == alice.end()) // Verifico se o 5 está no meu set
                cont++;
        }
    }
    cout << cont << endl;
}