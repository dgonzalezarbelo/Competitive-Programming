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

struct comp {
    bool operator()(ii const& p1, ii const& p2) {
        return p1.fi < p2.fi || (p1.fi == p2.fi && p1.se < p2.se);
    }
};

bool solve() {
    int n; cin >> n;
    if(!n) return false;
    vii v(n);
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
        m[v[i].se]++;
    }
    sort(v.begin(), v.end(), comp());
    int aplaudiendo = n;
    int tiempo = 0;
    auto it = m.end();
    it--;
    for(int i = 0; i < n; i++) {
        if(aplaudiendo >= v[i].se) {
            tiempo = max(tiempo, v[i].fi);
            m[v[i].se]--;
            aplaudiendo--;
            while(it->first > aplaudiendo) {
                aplaudiendo -= it->second;
                it->second = 0;
                if(it != m.begin()) it--;
                else break;
            }
        }
        else {
            m[v[i].se] = 0;
        }
    }
    cout << tiempo << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(solve());
    return 0;
}