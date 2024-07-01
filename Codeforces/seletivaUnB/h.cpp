#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);


int32_t main() {
    stack<int> pilha1,pilha2;

    for (int  i = 0; i < 5; i++)
    {   
        int aux;
        cin >> aux; // time1
        if(aux == -1){
            if(!pilha2.empty()){
                pilha2.pop();
            }
        }
        else{
        pilha1.push(aux);
        }
        cin >> aux; //time2
        if(aux == -1){
            if(!pilha1.empty()){
                pilha1.pop();
            }
        }
        else{
        pilha2.push(aux);
        }
    }

    int p1 = 0;
    while(!pilha1.empty()){
        p1+=pilha1.top();
        pilha1.pop();
    }
    
    int p2 = 0;
    while(!pilha2.empty()){
        p2+=pilha2.top();
        pilha2.pop();
    }

    if(p1 > p2){
        cout << 1 << endl;
    }else if(p2 > p1){
        cout << 2 << endl;
    }
    else{
        cout << 0 << endl;
    }
   
    return 0;
}

/*
5 9 16 20 -1 2 18 14 7 10

outro
9 18 19 20 -1 -1 -1 7 2 4


*/