#include <bits/stdc++.h>

using namespace std;

bool ordenar(string a,string b){
	return a.size()<b.size(); 
}

int main(){   
    string str;
    getline(cin,str);
   // set<int> p;
    istringstream iss(str);
    int num;
    set <int> numeros;

    while(iss >> num){
        numeros.insert(num);
    }
    string str2;
    getline(cin,str2);
	istringstream iss2(str2);
    vector<int> p;
    while(iss2 >> num){
        p.push_back(num);
    }
    /*
    sort(p.begin(),p.end());
    for (int i = 0; i < (int) p.size(); i++)
    {
        if(numeros.find(p[i]) != numeros.end())
            printf("%d Está mapeado\n",p[i]);
        else
            printf("%d Não está mapeado\n",p[i]);
    }*/
    
    



    return 0;
}
