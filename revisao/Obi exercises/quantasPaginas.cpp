#include <iostream>
#include <cmath> // Para usar a função ceil()

using namespace std;

int main() {
    int t;
    cin >> t;  // Leitura do número de casos de teste

    for (int i = 0; i < t; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int r_pages = a * c; // Páginas das respostas
        int q_pages = a * b; // Páginas das questões

        // Calcula o número total de páginas
        int total_pages = (r_pages / d) + (q_pages / d);

        // Calcula o resto de páginas para as partes restantes das respostas e questões
        int resto = (r_pages % d) + (q_pages % d);

        // Calcula o número de páginas adicionais necessárias para o resto
        int resto_pages = ceil((double)resto / d);

        // Adiciona as páginas adicionais ao total
        total_pages += resto_pages;

        // Imprime o resultado
        cout << "O livro contera " << total_pages;
        if (total_pages > 1) {
            cout << " paginas." << endl;
        } else {
            cout << " pagina." << endl;
        }
    }

    return 0;
}
