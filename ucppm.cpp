#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<char>> const& mat, vector<vector<bool>> & visited, int i, int j) {
    if(visited[i][j]) return 0;
    visited[i][j] = true;
    int total = 1;
    if(i > 0 && mat[i - 1][j] == '#')
        total += dfs(mat, visited, i - 1, j);
    if(i < mat.size() - 1 && mat[i + 1][j] == '#')
        total += dfs(mat, visited, i + 1, j);
    if(j > 0 && mat[i][j - 1] == '#')
        total += dfs(mat, visited, i, j - 1);
    if(j < mat[0].size() - 1 && mat[i][j + 1] == '#')
        total += dfs(mat, visited, i, j + 1);
    return total;
}

bool resuelveCaso() {
    int F, C; cin >> F >> C; cin.get();
    if(!cin) return false;
    string linea;
    vector<vector<char>> mat(F, vector<char>(C));
    vector<vector<bool>> visited(F, vector<bool>(C, false));
    for(int i = 0; i < F; i++) {
        getline(cin, linea);
        for(int j = 0; j < C; j++) {
            mat[i][j] = linea[j];
        }
    }
    int sol = 0;
    for(int i = 0; i < F; i++) {
        for(int j = 0; j < C; j++) {
            if(mat[i][j] == '#' && !visited[i][j]) {
                int plantacion = dfs(mat, visited, i, j);
                sol = max(sol, plantacion);
            }
        }
    }
    cout << sol << endl;
    return true;
}

int main() {
    while(resuelveCaso());
    return 0;
}  