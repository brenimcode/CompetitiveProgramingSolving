#include <bits/stdc++.h>

using namespace std;

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    if(!(a[0] < a[1]+a[2] && a[1] < a[0]+a[2] && a[2] < a[1]+a[0])){
        printf("n\n");
        return 0;
    }

    int hip = 0, catA,catB;

    for (int i = 0; i <3; i++)
    {
        if(hip < a[i]){
            hip = a[i];
        }
    }
    


    if(hip == a[0]){
        catA = a[1];
        catB = a[2];
    }else if(hip == a[1]){
        catA = a[0];
        catB = a[2];
    }
    else{
        catA = a[0];
        catB = a[1];
    }
    
    if(pow(hip,2) == pow(catA,2) + pow(catB,2)){
        printf("r\n"); // Triangulo retangulo
    }
    else if(pow(hip,2) > pow(catA,2) + pow(catB,2)){
        printf("o\n");
    }
    else{
        printf("a\n");
    }

    return 0;
}