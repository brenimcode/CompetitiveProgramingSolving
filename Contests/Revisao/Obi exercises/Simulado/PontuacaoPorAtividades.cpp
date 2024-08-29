#include <bits/stdc++.h>

using namespace std;

int main() {
    int e,a,c,i;

    cin >> e >> a >> c;
    char result;
    e*=2;
    a*=3;
    c*=5;
    if(e+a+c >= 200){
        result = 'O';
    }
    else if(e+a+c >= 150){
        result = 'S';
    }
    else if(e+a+c >= 100){
        result = 'B';
    }
    else{
        result = 'N';
    }

    cout << result << endl;

    return 0;
}