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

const int cota = 10000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin >> n) {
        vi valores(n), cantidades(n);
        for(int & x : valores) cin >> x;
        for(int & x : cantidades) cin >> x;
        int precio; cin >> precio;
        vvi dp(n, vi(precio + 1, cota));
        rep(k, 0, cantidades[n - 1] + 1) {
            if(k * valores[n - 1] > precio) break;
            dp[n - 1][k * valores[n - 1]] = k;
        }
        rep(i,0,n) dp[i][0] = 0;
        for(int i = n - 2; i >= 0; i--) {
            rep(p, 0, min(valores[i], precio + 1)) dp[i][p] = dp[i + 1][p];
            rep(p, valores[i], precio + 1) {
                for(int k = 0; k * valores[i] <= p && k <= cantidades[i]; k++) {
                    dp[i][p] = min(dp[i][p], dp[i + 1][p - k * valores[i]] + k);
                }
            }
        }
        int sol = dp[0][precio];
        if(sol == cota) {
            cout << "NO\n";
            continue;
        }
        cout << "SI";
        rep(i,0,n-1) {
            int max_k = 0;
            for(int k = 0; k * valores[i] <= precio && k <= cantidades[i]; k++) {
                if(dp[i + 1][precio - k * valores[i]] == sol - k) max_k = k;
            }
            cout << ' ' << max_k;
            precio -= max_k * valores[i];
            sol -= max_k;
        }
        cout << ' ' << precio / valores[n - 1] << '\n';
    }
    return 0;
}