#include <bits/stdc++.h>

using namespace std;

int main() {
    string str,result = "";
    int i;
    getline(cin, str);
    int len = str.size();

    for (i = 1; i < len; i++)
    {
        if(str[i-1] == 'p') {
            result += str[i];
            str[i] = '.';
        }
        if(str[i] == ' ') {
            result+=' ';
        }
    }


    


    cout << result;


    return 0;
}