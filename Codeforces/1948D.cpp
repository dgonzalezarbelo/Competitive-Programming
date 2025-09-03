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

void solve() {
    string s; cin >> s;
    int n = sz(s);
    vvi dp(n, vi(n, -1));
    for(int j = n - 1; j >= 0; j--) {
        for(int i = j - 1; i >= 0; i--) {
            if(s[i] != s[j] && s[i] != '?' && s[j] != '?') dp[i][j] = 0;
            else {
                dp[i][j] = 1;
                if(i < n - 1 && j < n - 1) dp[i][j] += dp[i + 1][j + 1];
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dp[i][j] == j - i) ans = max(ans, j - i);
        }
    }
    cout << 2 * ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}