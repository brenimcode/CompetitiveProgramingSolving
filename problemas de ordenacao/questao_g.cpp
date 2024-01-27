#include <bits/stdc++.h>

using namespace std;

int main(){   
    int n,c;
    cin >> n >> c;
    if(c >=2 && c<=10){
        printf("%d ",c);
    }
    else if(c==1){
        printf("Às ");
    }
    else if(c==11){
        printf("Valete ");
    }
    else if(c==12){
        printf("Dama ");
    }
    else if(c==13){
        printf("Rei ");
    }
    printf("de ");
    if(n == 0){
        printf("Paus\n");
    }
    else if(n == 1){
        printf("Ouro\n");
    }
    else if(n == 2){
        printf("Coração\n");
    }
    else if(n == 3){
        printf("Espada\n");
    }


    
    return 0;
}
