#include <bits/stdc++.h>

using namespace std;

int main() {

    int c_a,b_a,p_a;
    int c_r,b_r,p_r;
    cin >> c_a >> b_a >> p_a
     >> c_r >> b_r >> p_r;

    int sum =  0;
    //(c_r - c_a) + ( b_r - b_a) + (p_r - p_a);
    if((c_r - c_a) > 0){
        sum += (c_r - c_a);
    }
    if((b_r - b_a) > 0){
        sum += b_r - b_a;
    }
    if((p_r - p_a) > 0){
        sum += p_r - p_a;
    }

    cout << sum << endl;

    

    return 0;
}