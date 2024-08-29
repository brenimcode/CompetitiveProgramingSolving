#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main()
{
    int i;
    char letter;
    string text;
    cin >> letter;
    cin.ignore();
    getline(cin, text);
    int textSize = text.size();
    double sum_p = 0, sum_letter_p = 0;
    string word = "";
    for (i = 0; i < textSize; i++)
    {
        if (text[i] == ' ')
        {
            if (word.find(letter) != string::npos)
            {
                sum_letter_p++;
            }
            word = "";
            sum_p++;
        }
        else
        {
            word += text[i];
        }
    }
    if (word.find(letter) != string::npos)
    {
        sum_letter_p++;
    }
    sum_p++;
    printf("%.1f", (sum_letter_p / sum_p) * 100.0);

    return 0;
}