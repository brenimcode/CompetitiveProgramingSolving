#include <bits/stdc++.h>

#define DEBUG(x) cout << #x << " >>>> " << x << endl

using namespace std;

int main() {
    string str;
    getline(cin,str);
    string res = "";
    map<char, string> alfa = {
    {'A', "2"}, {'B', "2"}, {'C', "2"}, {'D', "3"}, {'E', "3"}, {'F', "3"}, {'G', "4"}, {'H', "4"}, {'I', "4"},
    {'J', "5"}, {'K', "5"}, {'L', "5"}, {'M', "6"}, {'N', "6"}, {'O', "6"}, {'P', "7"}, {'Q', "7"}, {'R', "7"},
    {'S', "7"}, {'T', "8"}, {'U', "8"}, {'V', "8"}, {'W', "9"}, {'X', "9"}, {'Y', "9"}, {'Z', "9"}
};


    for (int i = 0; i < (int) str.size(); i++)
    {
        if(str[i] != '-'){
            auto num = alfa.find(str[i]); // {TODO} Vou buscar o char 'A' por exemplo e retornar string 2.
            res+= num->second;
        }
        else{
            res+=str[i];
        }
    }
    
    cout << res << endl;
    
    return 0;
}
