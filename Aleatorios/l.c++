#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, d, i, j, count = 0;
    bool ver = true;
    vector<char> vet;
    char x;
    while (1)
    {
        cin >> n >> d;
        if (n == 0 && d == 0)
            break;
        vet.clear();
        for (i = 0; i < n; i++)
        {
            cin >> x;
            vet.push_back(x);
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (vet[i] > vet[j])
                {
                    ver = false;
                    break;
                }
            }
            if (ver == true)
            {
                vet.erase(vet.begin() + i);
                count++;
            }
            if (count == d)
                break;
            ver = true;

            
        }

        for (i = 0; i < (int)vet.size(); i++)
        {
            cout << vet[i];
        }
        cout << endl;
    }

    return 0;
}
