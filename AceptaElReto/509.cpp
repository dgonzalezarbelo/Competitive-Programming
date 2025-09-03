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

bool resuelveCaso() {
    int n, m; cin >> m >> n;
    if(!cin) return false;
    vector<vector<ll>> mat(n, vll(m));
    vector<vector<ll>> dp(n, vll(m, 1e10)); //Suma actual, minimo
    rep(i,0,n) {
        rep(j,0,m) {
            cin >> mat[i][j];
        }
    }
    dp[n - 1][m - 1] = 2;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(i == n - 1 && j == m - 1) continue;
            ll sol1 = 1e10, sol2 = 1e10;
            if(i < n - 1) sol1 = dp[i + 1][j];
            if(j < m - 1) sol2 = dp[i][j + 1];
            sol1 = max(ll(2), sol1 - mat[i][j]);
            sol2 = max(ll(2), sol2 - mat[i][j]);
            if(i < n - 1 && j < m - 1) dp[i][j] = min(sol1, sol2);
            else if (i < n - 1) dp[i][j] = sol1;
            else dp[i][j] = sol2;
        }
    }
    cout << dp[0][0] << endl;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso());
    return 0;
}