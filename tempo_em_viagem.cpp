#include <bits/stdc++.h>

using namespace std;

int main(){
    int d1,h1,m1,d2,h2,m2;
    int result;
    cin >> d1 >> h1 >> m1 >> d2 >> h2 >> m2;
    result = (d2-d1)*86400;
    int minutos1,minutos2;
    minutos1 = (h1*60)+m1;
    minutos2 = (h2*60)+m2;
    minutos1 = minutos2 - minutos1;
    minutos1 *= 60;
    cout << minutos1+result;


    
}   