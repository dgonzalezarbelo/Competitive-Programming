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

bool solve() {
    int n; cin >> n;
    if(!n) return false;
    vector<pair<ll,ll>> v(n);
    unordered_set<ll> s;
    ll sol = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        if(s.count(a)) sol = 0;
        s.insert(a);
        v[i] = mp(a,b);
    }
    if(sol != LLONG_MAX) {
        cout << sol << '\n';
        return true;
    }
    sort(v.begin(), v.end());
    bool haysol = false;
    pair<ll,ll> prev, cur = v[0];
    for(int i = 1; i < n; i++) {
        prev = cur;
        cur = v[i];
        ll m1 = prev.second, n1 = prev.first, m2 = cur.second, n2 = cur.first;
        if(m1 <= m2) continue;
        haysol = true;
        sol = min(sol, (n1-n2)/(m2-m1));
    }
    if(!haysol) cout << "SIN COLISION\n";
    else cout << sol << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(solve());
    return 0;
}