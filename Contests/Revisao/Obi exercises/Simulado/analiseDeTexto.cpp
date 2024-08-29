#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, j;
    string text, text2;
    getline(cin,text);
    istringstream stream(text);
    getline(cin, text2);

    vector<string> tokens;
    string token;
    while (getline(stream, token, ' '))
    {
        tokens.push_back(token);
    }
    int res = 0;
    for (i = 0; i < (int)text2.size(); i++)
    {
        for (j = 0; j < (int)tokens.size(); j++)
        {
            if (tokens[j].find(text2[i]) != string::npos)
            {
                tokens.erase(tokens.begin() + j);
                --j;
                res++;
            }
        }
    }

    cout << res << endl;

    return 0;
}