#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << " "

int main()
{
    int i;
    string a, b;

    getline(cin, a);
    getline(cin, b);

    while (a.size() < b.size())
    {
        a.insert(a.begin(), '0');
    }
    while (a.size() > b.size())
    {
        b.insert(b.begin(), '0');
    }
    string r1 = "", r2 = ""; // results
    for (i = 0; i < (int)a.size(); i++)
    {
        if (a[i] > b[i])
        {
            r1 += a[i];
        }
        if (a[i] < b[i])
        {
            r2 += b[i];
        }
        if (a[i] == b[i])
        {
            r2 += b[i];
            r1 += a[i];
        }
    }
    // convert STRING -> INT
    int num1, num2;
    if (r1 == "")
    {
        num1 = -1;
    }
    else
    {
        num1 = 0;
        for (i = 0; i < (int) r1.size(); i++)
        {
            num1 = num1 * 10 + (r1[i] - '0');
        }
    }
    if (r2 == "")
    {
        num2 = -1;
    }
    else
    {
        num2 = 0;
        for (i = 0; i < (int) r2.size(); i++)
        {
            num2 = num2 * 10 + (r2[i] - '0');
        }
    }

    if (num1 < num2)
    {
            cout << num1 << " ";
            cout << num2 << endl;
    }
    else
    {
            cout << num2 << " ";
            cout << num1 << endl;
    }

    return 0;
}