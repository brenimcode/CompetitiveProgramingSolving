#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << max(abs(str1[0] - str2[0]), abs(str1[1] - str2[1])) << endl;
    while (str1 != str2)
    {

        // Primeiro vemos a parte do X.
        
        // Se o INI tiver a esquerda do FIM.
        if (str1[0] < str2[0])
        {
            cout << "R";
            str1[0] += 1;
        }
        // Se o INI tiver a direita do FIM.
        else if (str1[0] > str2[0])
        {
            cout << "L";
            str1[0] -= 1;
        }

        //Agora ver a parte do Y.
        
        // Se o INI tiver abaixo do FIM
        if (str1[1] < str2[1])
        {
            cout << "U";
            str1[1] += 1;
        }
        // Se o INI tiver acima do FIM
        else if (str1[1] > str2[1])
        {
            cout << "D";
            str1[1] -= 1;
        }

        cout << endl;
    }
    return 0;
}