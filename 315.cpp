#include <bits/stdc++.h>
#pragma warning (disable : 4996)
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair

const double EPS = 1e-9;
const double INF = 1e9; //1e18 tambien suele ir bien
using ll = long long int;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using db = double;
using vdb = vector<db>;
using ldb = long double; //100 ceros pero poca precision decimal

vvi mat;
vector<vector<char>> mat_sol;
vii dir = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
vvb visited;

bool en_rango(int i, int j) {
    return i >= 0 && i < mat.size() && j >= 0 && j < mat[0].size();
}

void dfs(int i, int j) {
    if(visited[i][j]) return;
    visited[i][j] = true;
    if(mat[i][j] == -1) return;
    if(mat[i][j] > 0) {
        mat_sol[i][j] = mat[i][j] + '0';
        return;
    }
    mat_sol[i][j] = '-';
    for(auto p : dir) {
        if(en_rango(i + p.first, j + p.second))
            dfs(i + p.first, j + p.second);
    }
}

bool solve() {
    int f, c; cin >> f >> c;
    if(!cin) return false;
    mat.assign(f, vi(c, 0));
    mat_sol.assign(f, vector<char>(c, 'X'));
    visited.assign(f, vb(c, false));
    vii minas;
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            char aux; cin >> aux;
            if(aux == '*') {
                minas.push_back(mp(i, j));
                mat[i][j] = -1;
            }
        }
    }
    for(auto mina : minas) {
        for(auto p : dir) {
            if(en_rango(mina.first + p.first, mina.second + p.second) && mat[mina.first + p.first][mina.second + p.second] != -1) 
                mat[mina.first + p.first][mina.second + p.second]++;
        }
    }
    int q; cin >> q;
    bool muere = false;
    while(q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        if(muere) continue;
        if(mat[a][b] == -1) {
            muere = true;
            continue;
        }
        if(mat[a][b] > 0) mat_sol[a][b] = mat[a][b] + '0';
        if(mat[a][b] == 0) {
            dfs(a, b);
        }
    }
    if(muere) cout << "GAME OVER\n";
    else {
        for(int i = 0; i < f; i++) {
            for(int j = 0; j < c; j++) {
                cout << mat_sol[i][j];
            }
            cout << endl;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(solve());
    return 0;
}