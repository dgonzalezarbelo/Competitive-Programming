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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    while(cin >> t) {
        int n; cin >> n;
        vii v(n); // Profundidad, monedas
        for(ii & p : v) cin >> p.first >> p.second;
        vvi dp(t+1, vi(n, 0));
        rep(i,0,n) dp[0][i] = 0;
        rep(i,1,t+1) dp[i][n - 1] = (i >= 3 * v[n - 1].first ? v[n - 1].second : 0);
        for(int i = n - 2; i >= 0; i--) {
            for(int tt = 1; tt <= t; tt++) {
                dp[tt][i] = dp[tt][i + 1];
                if(tt >= 3 * v[i].first)
                    dp[tt][i] = max(dp[tt][i], dp[tt - 3 * v[i].first][i + 1] + v[i].second);
            }
        }
        cout << dp[t][0] << '\n';
        int tt = t;
        queue<ii> q;
        rep(i,0,n) {
            if(i < n - 1) {
                if(tt >= 3 * v[i].first && dp[tt][i] == dp[tt - 3 * v[i].first][i + 1] + v[i].second) {
                    q.push(v[i]);
                    tt -= 3 * v[i].first;
                }
            }
            else if(tt >= 3 * v[n - 1].first) {
                q.push(v[i]);
            }
        }
        cout << q.size() << '\n';
        while(!q.empty()) {
            ii p = q.front(); q.pop();
            cout << p.first << ' ' << p.second << '\n';
        }
        cout << "----\n";
    }   
    return 0;
}