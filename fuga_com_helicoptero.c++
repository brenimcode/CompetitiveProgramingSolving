#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h,p,f,d;
    cin >> h >> p >> f >> d;
    while(true)
    {
       printf("F=[%d],P = [%d], H = [%d]\n",f,p,h);
        if(f == -1){
            f = 15;
        }

        if(f == 16){
            f = 0;
        }

        if(f == h){
                //encontrou helicoptero
            cout << "S";
            return 0;
        }
        if(f == p){
            cout << "N";
            return 0;
        }

        f+=d;//Fugitivo está andando no circulo

    }
    
    return 0;
}