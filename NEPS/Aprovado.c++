#include <iostream>

using namespace std;

int main(){
    // Lendo a entrada do exercício
    double A, B;
    cin >> A >> B;
	if((A+B)/2 >= 7){
		cout << "Aprovado";
	}
	else if((A+B)/2 < 7 && (A+B)/2 >= 4){
		cout << "Recuperacao";
	}
		else{
			cout << "Reprovado";
		}
    // Seu código vai aqui

    return 0;
}
