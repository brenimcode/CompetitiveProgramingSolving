#include <bits/stdc++.h>
using namespace std;

#define NMAX 1010

int main() {
    int  v,a,n,b,i; // t é qtd de casos de teste,aaestas A e B
    cin >> v >> a;
    
    for(i=0;i<a;i++){
        cin >> n >> b;
    }
    a = -a+ ((v*(v-1))/2);
 
    printf("%d",a);
    return 0;
}
