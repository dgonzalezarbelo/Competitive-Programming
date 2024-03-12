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

int d;

struct comp {
    bool operator()(ii const& p1, ii const& p2) {
        return db(p1.fi) - db(d)*cos(asin(double(p1.se)/double(d))) < db(p2.fi) - db(d)*cos(asin(double(p2.se)/double(d)));
    }
};

bool solve(int t) {
    int n; cin >> n >> d;
    if(!n && !d) return false;
    vii v(n);
    for(ii & p : v) cin >> p.fi >> p.se;
    sort(v.begin(), v.end(), comp());
    // (x - d*cos(arcsin(h/d)), x + d*cos(arcsin(h/d)))
    db iz = db(v[0].fi) - db(d)*cos(asin(double(v[0].se)/double(d))), der = db(v[0].fi) + db(d)*cos(asin(double(v[0].se)/double(d)));
    int sol = 1;
    bool ok = true;
    for(int i = 1; i < n; i++) {
        if(v[i].se > d) {
            ok = false;
            break;
        }
        db niz = db(v[i].fi) - db(d)*cos(asin(double(v[i].se)/double(d))), nder = db(v[i].fi) + db(d)*cos(asin(double(v[i].se)/double(d)));
        if(niz > der) {
            sol++;
            iz = niz;
            der = nder;
        }
        else {
            iz = max(iz, niz);
            der = min(der, nder);
        }
    }
    cout << "Case " << t << ": ";
    if(ok) cout << sol << endl;
    else cout << -1 << endl;
    return true;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t = 0;
    while(solve(++t));
    return 0;
}