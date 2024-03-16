#include <bits/stdc++.h>

using namespace std;

int main(){
    int l1,l2,b1,b2,sum_l,sum_b;
    cin >> l1 >> l2 >> b1 >> b2;
    if(l1 == l2){
        sum_l = 2*(l1+l2);
    }
    else if(abs(l1-l2) == 1){
        sum_l = 3*(l1+l2);
    }
    else{
        sum_l = l1+l2;
    }

    if(b1 == b2){
        sum_b = 2*(b1+b2);
    }
    else if(abs(b1-b2) == 1){
        sum_b = 3*(b1+b2);
    }
    else{
        sum_b = b1+b2;
    }
    if(sum_l > sum_b){
        cout << "Lia";
    }
    else if(sum_l < sum_b){
        cout << "Carolina";
    }
    else{
        cout << "empate";
    }

}