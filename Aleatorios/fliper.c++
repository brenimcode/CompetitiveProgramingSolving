#include <iostream>

using namespace std;

int main(){
    // Lendo a entrada do exercício
    int p,r;
    cin >> p>> r;
	if(p < 0 || p>1 && r < 0 || r > 1){
		return 0;
	}
	if(p == 0){
		cout << "C";
	}
	else if(p == 1 && r==0){
		cout << "B";
	}
	else{
		cout << "A";
	}
    // Seu código vai aqui

    return 0;
}
