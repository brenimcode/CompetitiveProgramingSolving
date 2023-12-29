#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(){
    long int i,n,j, aux,k,num_x,num_y;
    cin >> n;
    cin.ignore();
    for (i = 0; i < n; i++)
    {
        num_y=0;
        string x;
        getline(cin,x);
        num_x = 0;
        long int pot_10 = 1,numero;
        for (j = 0; j < (int) x.size(); j++)
        {
            //eu acho o fim do numero e venho voltando.
            if(x[j] == '!'){
                //fim do numero, num vai de 0 até j-1
                for (k = j-1; k >= 0 ; k--)
                {
                    numero = x[k] - '0';
                    numero *= pot_10;
                    num_x += numero;
                    pot_10*=10;
                }
                num_y = x.size() - j;
                break;
                
            }
        }
        
        aux = 1;
        for (j = num_x; j > 1; j-=num_y)
        {
            aux *= j;
        }
        cout << aux << endl;
    }
    

    
}