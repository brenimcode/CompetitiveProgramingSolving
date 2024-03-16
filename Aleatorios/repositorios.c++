#include <bits/stdc++.h> // biblioteca magica

using namespace std;

int main(){
    int c,n,i;
    cin >> c >> n;
    int aux1,aux2;
    map <int,int> instalados;
    map <int,int> disponiveis;
    for (i = 0; i < c; i++)
    {
        cin >> aux1;
        cin >> aux2;
        instalados.insert(make_pair(aux1,aux2));
    }
    map <int,int>:: iterator temp;
    for (i = 0; i < n; i++)
    {
        cin >> aux1;
        cin >> aux2;
        temp = disponiveis.find(aux1);
        if(temp != disponiveis.end()){
            if(aux2 > (*temp).second){
                disponiveis.erase(temp);
            }
            else{
                continue;
            }
        }
        disponiveis.insert(make_pair(aux1,aux2));
    }

    cout << endl;
    map <int,int>:: iterator it;

    for (it = disponiveis.begin(); it != disponiveis.end(); it++)
    {
        temp = instalados.find((*it).first); //temp é o programa instalado, it é disp
    
        if((*temp).second < (*it).second)
            printf("%d %d\n",(*it).first, (*it).second);
    }

}
    