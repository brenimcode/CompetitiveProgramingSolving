#include <bits/stdc++.h>

using namespace std;

#define maxn 5000
#define maxv 100
typedef long long ll;

ll p[6];
int sum = 0;

int saque(int n, int s){
    if(n == 0){
        if(s == 0){
            sum++;
            return 1;
        }
        return 0;
    }
    int aux = saque(n-1,s);
    if(aux == 0 && p[n]<=s)
        aux = saque(n-1,s-p[n]);
    sum++;
    return aux;
}

int memo[maxn][maxv];

int t(int idx,int val){
    if(memo[idx][val] == -1){
        //calcula 
        memo[idx][val] = min(1+t(idx,val-s[idx]),f(idx+1,val)); // memo recebe o minimo entre pegar uma moeda duas vezes, e nao pegar novamente;

    }
    return memo[idx][val];

}


int main(){
    ll s;
    cin >> s; //saque
    for(int i=0;i<6;i++){
        cin >> p[i];
    }
     //numero de notas de 2,5,10,50,100 disponvieis p[2,5,10,20,50,100]
    saque(6,s);
    cout << sum;


}