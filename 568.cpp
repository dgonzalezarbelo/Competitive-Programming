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

vi dias;

int dp(int i, vi const& v, queue<ii> & q) {
    if(i == v.size() - 1) return 1;
}

bool solve() {
    int n; cin >> n;
    if(!cin) return false;
    vii v(n);
    rep(i,0,n) {
        int a, b, c, d; scanf("%d-%d %d-%d", &a, &b, &c, &d);
        v[i] = mp(a + b * 40, c + 40 * d);
    }
    queue<ii> q;
    return true;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    while(solve());
    return 0;
}