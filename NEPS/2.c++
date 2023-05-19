#include <iostream> //biblioteca usado para ler e imprimir
using namespace std;
// A turma do colégio vai fazer uma excursão na serra e todos os alunos e monitores vão tomar um bondinho para subir 
// até o pico de uma montanha. A cabine do bondinho pode levar 50 pessoas no máximo, contando alunos e monitores, durante uma viagem até o pico.
int main()
{
    int A, M;
    cin >> A >> M;
    if ((A >= 1 && A <= 50) && (M >= 1 && M <= 50))
    {
        if ((A + M) <= 50)
        {
            cout << "S";
        }
        else
        {
            cout << "N";
        }
    }
    else {
        cout << "N";
    }
    return 0;
}
