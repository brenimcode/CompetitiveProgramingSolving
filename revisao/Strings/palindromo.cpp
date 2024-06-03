#include <bits/stdc++.h>

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;


int main() {
    _
    int n;
    cin >> n;
    cin.ignore();
    string str;
    cin >> str;

    DEBUG(str);
    int num = 0;
    cout << num << ' ';
    for (int i = 0; i < n; i++)
    {
        if(str[i] == 'B' && num == 0){
            cout << num << " ";
        }
        else if(str[i] == 'B'){
            cout << --num << " ";
        }
        else if(str[i] == 'A'){
            cout << ++num << " ";
        }
    }
    

    
    
    return 0;
}
