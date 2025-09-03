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

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    FT ft(n);
    rep(i,0,n) ft.update(i, 1);
    vi qa(n / 2), qb(n / 2);
    rep(i,0,n / 2) cin >> qa[i];
    rep(i,0,n / 2) cin >> qb[i];
    vi sola(n / 2), solb(n / 2);
    rep(i,0,n / 2) {
        int pos = ft.lower_bound(qa[i]);
        ft.update(pos, -1);
        sola[i] = pos + 1;
        
        pos = ft.lower_bound(qb[i]);
        ft.update(pos, -1);
        solb[i] = pos + 1;
    }
    rep(i,0,n / 2) {
        if(i) cout << ' ';
        cout << sola[i];
    }
    cout << '\n';
    rep(i,0,n / 2) {
        if(i) cout << ' ';
        cout << solb[i];
    }
    cout << '\n';
    return 0;
}