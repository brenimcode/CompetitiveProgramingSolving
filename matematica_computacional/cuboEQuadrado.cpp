#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    int count = 0;

    // Calcular o menor valor de n tal que n^6 >= A
    long long lower_bound = ceil(pow(A, 1.0/6));
    // Calcular o maior valor de n tal que n^6 <= B
    long long upper_bound = floor(pow(B, 1.0/6));

    // Iterar de lower_bound até upper_bound e contar os valores que estão dentro do intervalo
    for (long long n = lower_bound; n <= upper_bound; ++n) {
        long long power = n * n * n * n * n * n;
        if (power >= A && power <= B) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
