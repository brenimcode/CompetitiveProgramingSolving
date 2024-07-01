#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);


int mdc(int a, int b){
    if(b == 0){
        return a;
    }
    return mdc(b,a%b);
}

int sinfonia(int a,int b, int c){
    int aux = mdc(a,b);
    return mdc(aux,c);
}

int32_t main() {
    _

    string str;
    getline(cin,str); 
    int n = str.size();

    cout << ' ';
    for (int i = 0; i < n+2; i++)
    {
        cout << '_';
    }
    cout << "\n< ";
    cout << str;    
    cout << " >\n";
     cout << ' ';
     for (int i = 0; i < n+2; i++)
    {
        cout << '=';
    }
    cout << endl;


    cout << "        \\   ^..^      /\n         \\  /_/\\_____/\n               /\\   /\\\n              /  \\ /  \\  \n";
   
    return 0;
}
