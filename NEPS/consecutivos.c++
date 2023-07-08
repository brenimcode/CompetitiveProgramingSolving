#include <iostream> //entrada e saida cin cout
using namespace std;

int main(){
    int n, *valores,i,*pontos,j=0,f;
    cin >> n;
    valores = new int[n];
    pontos = new int[n];

    for (i = 0; i < n; i++)
    {
        cin >> valores[i];
    }
    for (i = 0; i < n; i++)
    {
        pontos[i] = 1;
    }

    for (i = 0; i < n; i++)
    {
        if(valores[i] == valores[i+1]){
            pontos[j]++;
        }
        else{
            j++;
        }
    }

    f = pontos[0];

    for(i=0;i<n;i++){
        if(f <= pontos[i]){
            f = pontos[i];
        }
    }
    cout << f << endl;
    delete pontos;
    delete valores;
}