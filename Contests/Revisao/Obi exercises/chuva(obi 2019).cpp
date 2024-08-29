#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define DMAX 805

// Global variables
int n, m; // n = rows, m = columns
char mat[DMAX][DMAX];

// Function to simulate the rain flow
void funcao(int x, int y) {
    // Check bounds
    if (x < 0 || x >= n || y < 0 || y >= m) return;

    // Check downward direction
    if (mat[x + 1][y] == '.' && x + 1 < n) { 
        mat[x + 1][y] = 'o';
        funcao(x + 1, y);
    }

    // Check rightward direction
    if (mat[x][y + 1] == '.' && mat[x + 1][y] == '#' && x + 1 < n && y + 1 < m) { 
        mat[x][y + 1] = 'o';
        funcao(x, y + 1);
    }

    // Check leftward direction
    if (mat[x][y - 1] == '.' && mat[x + 1][y] == '#' && x + 1 < n && y - 1 >= 0) { 
        mat[x][y - 1] = 'o';
        funcao(x, y - 1);
    }
} 

int main() {
    // Variables
    int i, j;
    cin >> n >> m; // Input number of rows and columns
    int x, y;

    // Read matrix and find the initial position of 'o'
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'o') {
                x = i;
                y = j;
            }
        }   
    }

    // Start the simulation from the initial position
    funcao(x, y);

    // Output the final state of the matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << mat[i][j]; 
        }
        cout << endl;
    }

    return 0;
}
