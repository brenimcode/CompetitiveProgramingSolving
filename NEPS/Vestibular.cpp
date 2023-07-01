#include <iostream> //Entrada e saida de dados i imput e o outpout
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    int n,i,v=0;
    char *str,*gabarito;
    cin >> n;
    gabarito = (char *) malloc(n*sizeof(char));
    for (i = 0; i < n; i++)
    {
        cin >> gabarito[i];
    }
    gabarito[i] = '\0';

    str = (char *) malloc(n*sizeof(char));
    for (i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    str[i] = '\0';
    
    for (i = 0; gabarito[i] != '\0'; i++)
    {
        if(gabarito[i] == str[i]){
            v++;
        }
    }
    cout << v;
    
    
}
