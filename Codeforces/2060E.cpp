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

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, m1, m2; cin >> n >> m1 >> m2;
        UF uf1(n + 1), uf2(n + 1);
        vii aristas1(m1), aristas2(m2);
        for(ii & p : aristas1) cin >> p.first >> p.second;
        for(ii & p : aristas2) {
            cin >> p.first >> p.second;
            uf2.join(p.first, p.second);
        }
        int sol = 0;
        for(ii p : aristas1) {
            if(!uf2.sameSet(p.first, p.second)) sol++;
            else uf1.join(p.first, p.second);
        }
        for(ii p : aristas2) {
            if(!uf1.sameSet(p.first, p.second)) {
                sol++;
                uf1.join(p.first, p.second);
            }
        }
        cout << sol << '\n';
    }
    return 0;
}