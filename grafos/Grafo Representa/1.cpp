#include <bits/stdc++.h>

using namespace std;

char alfabeto[] = {
    'a', 'b', 'c', 'd', 'e', 
    'f', 'g', 'h', 'i', 'j', 
    'k', 'l', 'm', 'n', 'o', 
    'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z'
};

bool dfs(map<char, vector<char>> &graph, char src, set<char> &visited, set<char> &group);
int dfsCount(map<char, vector<char>> &graph);

int main() {
    // Lendo o número de casos de teste:
    size_t N;
    cin >> N;

    // Casos de teste:
    for (size_t i = 0; i < N; i++) {
        // V: Vertices; E: Edges
        size_t V, E;
        cin >> V >> E;
        printf("Case #%d:\n\n",i++);
        // Criando o grafo:
        map<char, vector<char>> grafo;
        
        for (size_t j = 0; j < V; j++) {
            grafo.insert(pair<char, vector<char>>(alfabeto[j], vector<char>()));
        }

        // Criando as conexões do grafo:
        for (size_t j = 0; j < E; j++) {
            char n1, n2;
            cin >> n1 >> n2;
            grafo[n1].push_back(n2);
            grafo[n2].push_back(n1);
        }

        cout << dfsCount(grafo) << endl;

    }

    return 0;
}

/*
    a -> [b, c]    [-1]
    b -> [a, c]    [-1]
    c -> [a, b]    [-1]
    d -> []        [-1]
    e -> [f, b]    [-1]
    f -> [e]       [-1]

    set = {a, b, c}
*/


bool dfs(map<char, vector<char>> &graph, char src, set<char> &visited, set<char> &group) {
    if (visited.find(src) != visited.end()) {
        return false;
    }

    visited.insert(src);
    group.insert(src);

    for (char neighbor : graph[src]) {
        dfs(graph, neighbor, visited, group);
    }
    return true;
}


int dfsCount(map<char, vector<char>> &graph) {
    set<char> visited;
    set<char> group;
    int count = 0;

    for (auto par : graph) {
        if (dfs(graph, par.first, visited, group)) {
            for (char node : group) {
                cout << node << ',';
            }
            cout << endl << endl;
            
            group.clear();
            count++;
        }
    }


    return count;
}