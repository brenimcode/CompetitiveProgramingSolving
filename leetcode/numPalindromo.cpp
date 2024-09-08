#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int x) {
    string str = to_string(x);
    string str2 = str;
    reverse(str.begin(),str.end());
    return str2 == str;        
}

int main()
{

}