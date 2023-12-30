#include <bits/stdc++.h>

using namespace std;

int main(){
    int ha,ma,hr,mr;
    cin >> ha >> ma >> hr >> mr;
    ma = ma+ha*60;
    ma+=45;
    mr = mr+hr*60;
    int result = mr-ma;
    // mr > ma
    if(result >= 0)
        printf("Sucesso");
    else
        printf("Atrasado %d",-1*result);
}