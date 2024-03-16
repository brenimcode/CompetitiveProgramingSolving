#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (-a + b - c == 0)
    {
        cout << 'S';
    }
    else if (-a + b + c == 0)
    {
        cout << 'S';
    }
    else if (-a - b + c == 0)
    {
        cout << 'S';
    }
    else if (a - b + c == 0)
    {
        cout << 'S';
    }
    else if (a - b - c == 0)
    {
        cout << 'S';
    }
    else if (-a - b + c == 0)
    {
        cout << 'S';
    }//caso com 2 numeros apenas
    else if (a - b == 0)
    {
        cout << 'S';
    }
    else if (a - c == 0)
    {
        cout << 'S';
    }
    else if (b - c == 0)
    {
        cout << 'S';
    }
    else if ( b - a == 0)
    {
        cout << 'S';
    }
    else if ( c - a == 0)
    {
        cout << 'S';
    }
    else if ( c - b == 0)
    {
        cout << 'S';
    }
    else
    {
        cout << 'N';
    }
}