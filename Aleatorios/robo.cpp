#include <bits/stdc++.h>
 
using namespace std;
const int maxn = 1e5 + 10;
int n, c,s;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> c >> s; // estações, comandos, estacao mais proxima a area devastada
    int atual = 1; // estacao atual
    int sum = 0;
    if(atual == s) sum++;
    for(int i=1;i<=c;i++){
        int a;
        cin >> a;
        if(a == 1){
            //mover sentido horário
            atual++;
            if(atual > n) atual = 1;

        }else{
            // anti-horário
            atual--;
            if(atual < 1) atual = n;
        }
        if(atual == s){
            sum++;
        }
        
    }

    cout << sum << "\n";

    return 0;
} 