#include <bits/stdc++.h>

using namespace std;

int main(){
    int i,j,k;
    string a;
    vector<char> result;
    getline(cin,a);
    //string alfabeto = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};
    int n = a.size();

    for( i = 0; i < n; i++){
            if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
                result.push_back(a[i]);
            }
            else{

                result.push_back(a[i]);
                j = a[i];
                k = a[i];
                while(1){
                    j--;
                    k++;
                    if(j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u'){
                        result.push_back(j);
                        break;
                    }
                    if(k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u'){
                        result.push_back(k);
                        break;
                    }

                }
                if(a[i]+1 == 'a' || a[i]+1 == 'e' || a[i]+1 == 'i' || a[i]+1 == 'o' || a[i]+1 == 'u') {result.push_back(a[i]+2);}
                else if(a[i] == 'z'){result.push_back(a[i]); }
                else {result.push_back(a[i]+1);}

            }
    }

    for(i=0;i<(int)result.size();i++)
        cout << result[i];







    return 0;
}
