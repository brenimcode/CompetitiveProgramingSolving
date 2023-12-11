#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d, cont,i;
    string s, s2;
    while(cin>>n>>d){
        if(n==0 && d==0)
            return 0;
        cin>>s;//3759
        cont=d;
        for(i=0; i<s.size(); i++){
            while(s2.size()>0 && s[i]>s2.back() && cont>0 ){
                cont--;
                s2.pop_back();
            }
            if(s2.size()<n-d)
                s2.push_back(s[i]);//s2=3
        }
        cout << s2 << endl;
        s2="";
    }
}
