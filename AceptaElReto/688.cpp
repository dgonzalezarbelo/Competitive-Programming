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
    int c, m, n; cin >> c >> m >> n;
    if(!cin) return false;
    ll a, b; cin >> a >> b;
    n--;
    ll cur = b - a, prev;
    ll MIN_DIST = cur, MAX_DIST = cur;
    bool ok = true;
    while(n--) {
        a = b;
        cin >> b;
        prev = cur;
        cur = b - a;
        MIN_DIST = min(MIN_DIST, cur);
        MAX_DIST = max(MAX_DIST, cur);
        if(abs(cur - prev) > c) ok = false;
    }
    if(MAX_DIST - MIN_DIST > m) ok = false;
    if(ok) cout << "Ok\n";
    else cout << "Tropiezo\n";
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(solve());
    return 0;
}