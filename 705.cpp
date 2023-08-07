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
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using db = double;
using vdb = vector<db>;
using ldb = long double; //100 ceros pero poca precision decimal

bool simula(vi const& v, int salto) {
    int s = salto;
    int prev, cur = 0;
    for(int i = 0; i < sz(v); i++) {
        prev = cur;
        cur = v[i];
        if(cur - prev > s) return false;
        else if(cur - prev == s) s--;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vi v(n);
    int prev, cur = 0;
    int max_dist = INT_MIN, min_dist = INT_MAX;
    for(int i = 0; i < n; i++) {
        prev = cur;
        cin >> cur;
        v[i] = cur;
        max_dist = max(max_dist, cur - prev);
        min_dist = min(min_dist, cur - prev);
    }
    int ini = 1, fin = v[sz(v) - 1] + 1;
    while(ini < fin) {
        if(ini == fin - 1) {
            if(simula(v,ini)) fin--;
            break;
        }
        int m = (ini + fin) / 2;
        if(simula(v,m)) fin = m;
        else ini = m;
    }
    cout << fin << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}