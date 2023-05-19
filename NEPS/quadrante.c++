#include <iostream>

using namespace std;

int main(){
    // Seu código vai aqui
	int x;
	int y;
	cin >> x >> y;
	if(x<-100 && y<-100){
		return 0;
	}
	
	if(x>0 && y>0){
		cout << "Q1";
	}
	else if(x>0 && y<0){
		cout << "Q4";
	}
	else if(x<0 && y>0){
		cout << "Q2";
	}
	else if(x<0 && y<0){
		cout <<"Q3";
	}
	else if(x==0 || y==0){
		cout <<"eixos";
	}
		
    return 0;
}
