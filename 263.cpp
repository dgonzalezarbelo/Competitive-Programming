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

bool resuelveCaso() {
    int n; cin >> n;
    if(!n) return false;
    vector<vector<char>> mat(n, vector<char>(n));
    rep(i,0,n) rep(j,0,n) cin >> mat[i][j];
    char c;
    while(cin >> c && c != 'x') {
        int a; cin >> a;
        if(c == 'f') {
            if(a < 0) {
                a = abs(a);
                a--;
                char first = mat[a][0];
                rep(i,0,n - 1) mat[a][i] = mat[a][i + 1];
                mat[a][n - 1] = first;
            }
            else {
                a--;
                char last = mat[a][n - 1];
                for(int i = n - 1; i > 0; i--) mat[a][i] = mat[a][i - 1];
                mat[a][0] = last;
            }
        }
        else {
            if(a < 0) {
                a = abs(a);
                a--;
                char first = mat[0][a];
                rep(i,0,n - 1) mat[i][a] = mat[i + 1][a];
                mat[n - 1][a] = first;
            }
            else {
                a--;
                char last = mat[n - 1][a];
                for(int i = n - 1; i > 0; i--) mat[i][a] = mat[i - 1][a];
                mat[0][a] = last;
            }
        }
    }
    rep(i,0,n) {
        rep(j,0,n) cout << mat[i][j];
        cout << '\n';
    }
    cout << "---\n";
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso());
    return 0;
}