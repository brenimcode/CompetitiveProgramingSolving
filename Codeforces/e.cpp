#include <bits/stdc++.h>

#define DEBUG(x) cout << #x << " >>>> " << x << endl

using namespace std;

int main() {
    int N;
    cin >> N;
    
    string str;
    cin.ignore();
    getline(cin,str);
    
    string result = "";
    int i = 0;
    reverse(str.begin(),str.end());

    while(i < N)
    {
        
        if(str[i] == 'b'){
            if(i+1 <= N && str[i+1] == 'a'){
                result+="0";
                i += 2;
            }else{
                result = "(:";
                break;
            }
        }
        else{
            if((i + 2) <= N && str[i+1] == 'b' && str[i + 2] == 'a'){
                result+="1";
                i+=3;
            }
            else{
                result = "(:";
                break;
            }
        }
    }

   reverse(result.begin(), result.end());
    cout << result << endl;
    return 0;
}
