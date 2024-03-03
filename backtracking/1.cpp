#include <bits/stdc++.h>
using namespace std;

void impressao(int n){
    if(n == 1){
        printf("%d\n",n);
    }
    else{
        printf("%d\n", n);
        impressao(n-1);
    }
}

int main() {
    impressao(10);
    return 0;
}
