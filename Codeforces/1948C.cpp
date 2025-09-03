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
using ull = unsigned long long;
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
vvi visited;



bool dfs(int i, int j) {
    if(visited[i][j]) return false;
    visited[i][j] = true;
    if(i == 1 && j == mat[0].size() - 1) return true;
    bool ans = false;
    if(i < 1) {
        if(mat[i + 1][j] == '>') {
                ans |= dfs(i + 1, j + 1);
        }
        else
            ans |= dfs(i + 1, j - 1);
    }
    if(i > 0) {
        if(mat[i - 1][j] == '>') {
                ans |= dfs(i - 1, j + 1);
        }
        else
            ans |= dfs(i - 1, j - 1);
    }
    if(j > 0) {
        if(mat[i][j - 1] == '<') {
                ans |= dfs(i, j - 2);
        }
    }
    if(j < mat[0].size() - 1) {
        if(mat[i][j + 1] == '>') {
                ans |= dfs(i, j + 2);
        }
    }
    return ans;
}

void solve() {
    int n; cin >> n; cin.get();
    mat.assign(2, vector<char>(n));
    visited.assign(2, vi(n, false));
    for(int i = 0; i < 2; i++) {
        string s; getline(cin, s);
        for(int j = 0; j < n; j++) {
            mat[i][j] = s[j];
        }
    }
    if(dfs(0,0)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}