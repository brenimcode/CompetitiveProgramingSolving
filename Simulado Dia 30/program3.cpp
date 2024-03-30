#include <iostream>
#include <vector>

using namespace std; // Adicionando o namespace std

// Define a direção dos vizinhos (cima, baixo, esquerda, direita)
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// Função DFS para verificar se um "1" está conectado à borda
void dfs(int x, int y, vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    matrix[x][y] = '2'; // Marca como visitado

    for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] == '1') {
            dfs(nx, ny, matrix);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // Lê as dimensões da matriz

    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j]; // Lê a matriz (0 ou 1)
        }
    }

    // Verifica se os "1" estão conectados à borda
    for (int i = 0; i < n; ++i) {
        if (matrix[i][0] == '1') {
            dfs(i, 0, matrix);
        }
        if (matrix[i][m - 1] == '1') {
            dfs(i, m - 1, matrix);
        }
    }
    for (int j = 0; j < m; ++j) {
        if (matrix[0][j] == '1') {
            dfs(0, j, matrix);
        }
        if (matrix[n - 1][j] == '1') {
            dfs(n - 1, j, matrix);
        }
    }

    // Substitui os "1" não conectados à borda por "0"
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == '1') {
                matrix[i][j] = '0';
            }
        }
    }

    // Imprime a matriz resultante
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(matrix[i][j] != '2')
                cout << matrix[i][j];
            else
                cout << '1';
        }
        cout << "\n";
    }

    return 0;
}
