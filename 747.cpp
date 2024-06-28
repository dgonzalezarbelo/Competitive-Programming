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

int f, c;
vvi mat, vis;

bool dfs(int i, int j) {
    if(vis[i][j]) return false;
    vis[i][j] = true;
    if(i == f - 1 && j == c - 1) return true;
    if(i > 0 && mat[i - 1][j] && dfs(i - 1, j)) return true;
    if(i < f - 1 && mat[i + 1][j] && dfs(i + 1, j)) return true;
    if(j > 0 && mat[i][j - 1] && dfs(i, j - 1)) return true;
    if(j < c - 1 && mat[i][j + 1] && dfs(i, j + 1)) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> f >> c && f && c) {
        cin.get();
        mat.assign(f, vi(c, 0));
        vis.assign(f, vi(c, 0));
        rep(i,0,f) {
            string s;
            getline(cin, s);
            rep(j,0,c) {
                if(s[j] == '.') mat[i][j] = 1;
            }
        }
        if(dfs(0, 0)) cout << "SI\n";
        else cout << "NO\n";
    }
    return 0;
}