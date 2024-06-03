#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string str;
    cin.ignore();
    getline(cin, str);

    vector<vector<char>> alfabeto(6, vector<char>(6));
    vector<char> letras = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'L',
                           'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int idx = 0;
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            alfabeto[i][j] = letras[idx++];
        }
    }

    for (int k = 0; k < (int)str.size(); k++)
    {
        int x, y;
        if (str[k] == 'C' || str[k] == 'K')
        {
            x = 1;
            y = 3;
        }
        else
        {
            bool ver = false;
            for (int i = 1; i <= 5; ++i)
            {
                for (int j = 1; j <= 5; ++j)
                {
                    if (str[k] == alfabeto[i][j])
                    {
                        x = i;
                        y = j;
                        ver = true;
                        break;
                    }
                }
                if (ver)
                {
                    break;
                }
            }
        }
        
        for (int it = 0; it < x; it++)
        {
            printf("*");
        }
        printf(" ");
        for (int it = 0; it < y; it++)
        {
            printf("*");
        }
        printf(" ");
    }

    return 0;
}
