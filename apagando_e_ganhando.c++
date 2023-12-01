#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, d, i, x, j;
    bool ver = true;
    vector<int> vet;
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
        for (i = 0; i < d; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (vet[i] > vet[j])
                {
                    ver = false;
                }
            }
            if (ver == true)
                vet.erase(vet.begin() + i);
            ver = true;
        }
        for (i = 0; i < vet.size(); i++)
        {
            cout << vet[i];
        }
        
    }

    return 0;
}
