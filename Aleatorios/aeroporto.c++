#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,v,i,temp,maior,j=1;
    while(cin >> a >> v){
        if(a == 0 && v == 0)
            break;
        int aeroportos[a];
        for (i = 0; i < a; i++)
             aeroportos[i] = 0;
        for (i = 0; i < v; i++)
        {
            cin >> temp;
            aeroportos[temp-1]++;
            cin >> temp;
            aeroportos[temp-1]++;
        }
        
        maior = aeroportos[0];
        for (i = 1; i < a; i++)
        {
            if(maior < aeroportos[i]){
                maior = aeroportos[i];
            }
        }
        printf("Teste %d\n",j);
        j++;
        for (i = 0; i < a; i++)
        {
            if(maior == aeroportos[i]){
                printf("%d ",i+1);
            }
        }
        printf("\n\n");
        
    }
}