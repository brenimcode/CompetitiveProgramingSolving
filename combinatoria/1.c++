#include <bits/stdc++.h>

using namespace std;

long long int n[101];

unsigned long long int fib(unsigned long long int a)
{
    if (n[a] != -1)
        return n[a];

    return (n[a] = fib(a - 1) + fib(a - 2) + fib(a - 3));
}

int main()
{
    n[0] = 1;
    n[1] = 1;
    n[2] = 1;
    n[3] = 1;

    for (int i = 4; i <= 100; i++)
    {
        n[i] = -1;
    }

    int a;
    cin >> a;

    cout << fib(a) << endl;

    return 0;
}
