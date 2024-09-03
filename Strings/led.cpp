#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " --->>> " << x << endl

int32_t main() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string str;
        getline(cin, str);
        int len = str.size();
        int leds = 0;
        for(int i=0;i<len;i++) {
            if(str[i] == '1') {
                leds+=2;
            }
            else if(str[i] == '2' || str[i] == '3'||str[i] == '5' ){
                leds+=5;
            }
            else if(str[i] == '4'){
                leds+= 4;
            }
            else if(str[i] == '6' || str[i] == '9' || str[i] == '0'){
                leds+=6;
            }
            else if(str[i] == '7'){
                leds+=3;
            }
            else if(str[i] == '8'){
                leds+=7;
            }
        }

        cout << leds << " leds"<< endl;

    }

    return 0;
}
