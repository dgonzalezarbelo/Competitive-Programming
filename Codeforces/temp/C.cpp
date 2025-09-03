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
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vvi mat(n, vi(n));
        rep(i,0,n) rep(j,0,n) cin >> mat[i][j];
        vi v(n + 1);
        rep(i,0,n) {
            int seguidos = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(mat[i][j] != 1) break;
                seguidos++;
            }
            v[seguidos]++;
        }
        if(n == 1) {
            cout << "1\n";
            continue;
        }
        int sol = 1;
        for(int i = 1; i <= n; i++) {
            sol += min(v[i], i);
            sol = min(sol, i);
        }
        cout << min(sol, n) << '\n';
    }
    return 0;
}