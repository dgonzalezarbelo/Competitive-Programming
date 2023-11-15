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

vector<vector<char>> mat;
vvb visited;

int dfs(int i, int j) {
    if(visited[i][j]) return 0;
    visited[i][j] = true;
    int sol = 1;
    if(i > 0 && mat[i - 1][j] == '#') sol += dfs(i - 1, j);
    if(i < mat.size() - 1 && mat[i + 1][j] == '#') sol += dfs(i + 1, j);
    if(j > 0 && mat[i][j - 1] == '#') sol += dfs(i, j - 1);
    if(j < mat[0].size() - 1 && mat[i][j + 1] == '#') sol += dfs(i, j + 1);
    return sol;
}

bool solve() {
    int n, m; cin >> n >> m; cin.get();
    if(!cin) return false;
    mat.assign(n, vector<char>(m, 'a'));
    for(int i = 0; i < n; i++) {
        string s; getline(cin, s);
        for(int j = 0; j < m; j++) 
            mat[i][j] = s[j];
    }
    visited.assign(n, vb(m, false));
    int sol = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && mat[i][j] == '#') sol = max(sol, dfs(i, j));
        }
    }
    cout << sol << endl;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(solve());
    return 0;
}