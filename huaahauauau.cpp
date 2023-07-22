#include <iostream>
#include <string> //string em C++
using namespace std;

int main(){
    int i,j=0,v=0,tam;
    string linha;
    cin >> linha;
    tam = linha.size();
    char a1[tam];
    char a2[tam];
    for (i = 0,j=0; i < tam; i++)
    {
        if(linha[i] == 'a' or linha[i] == 'e' or linha[i] == 'o' or linha[i] == 'i' or linha[i] == 'u'){
            a1[j] = linha[i];
            j++;
        }
    }
    a1[j] = '\0';
    for (i = tam-1,j=0; i >= 0; i--)
    {
        if(linha[i] == 'a' or linha[i] == 'e' or linha[i] == 'o' or linha[i] == 'i' or linha[i] == 'u'){
            a2[j] = linha[i];
            j++;
        }
    }
   a2[j] = '\0';
    for (i = 0; a1[i] != '\0'; i++)
    {
        if(a1[i] != a2[i]){
            v = 1;
        }
    }
    if(v == 1){
        cout << 'N';
    }
    else{
        cout << 'S';
    }
}