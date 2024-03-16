#include <bits/stdc++.h>

using namespace std;

void charada(string &s, int k) {
    int n = s.size();
    vector<pair<char, int>> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = {s[i], i};
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j > 0 && v[j].second < v[j - 1].second) {
            swap(v[j], v[j - 1]);
            --j;
        }
        s[i] = v[i].first;
    }
}

int main() {
    string a;
    int i;
    
    // Lê a linha inteira até a quebra de linha
    getline(cin, a);
    
    // Lê o valor de K
    cin >> i;
    
    // Descarta a quebra de linha pendente
    cin.ignore();
    
    charada(a, i);
    cout << a << endl;
    return 0;
}
