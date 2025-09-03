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

struct LCA {
	int N; vvi par, adj; vi depth;
	void init(int _N) {  N = _N;
		int d = 1; while ((1<<d) < N) ++d;
		par.assign(d,vi(N)); adj.resize(N); depth.resize(N);
	}
	void ae(int x, int y) { adj[x].push_back(y), adj[y].push_back(x); }
	void gen(int R = 0) { par[0][R] = R; dfs(R); }
	void dfs(int x = 0) {
		rep(i,1,sz(par)) par[i][x] = par[i-1][par[i-1][x]];
		for(auto y : adj[x]) if (y != par[0][x]) 
			depth[y] = depth[par[0][y]=x]+1, dfs(y);
	}
	int jmp(int x, int d) {
		rep(i,0,sz(par)) if ((d>>i)&1) x = par[i][x];
		return x; 
    }
	int lca(int x, int y) {
		if (depth[x] < depth[y]) swap(x,y);
		x = jmp(x,depth[x]-depth[y]); if (x == y) return x;
		for(int i = sz(par) - 1; i >= 0; i--) {
			int X = par[i][x], Y = par[i][y];
			if (X != Y) x = X, y = Y;
		}
		return par[0][x];
	}
	int dist(int x, int y) { // # edges on path
		return depth[x]+depth[y]-2*depth[lca(x,y)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    LCA lca;
    lca.init(n);
    rep(i,0,n-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        lca.ae(a, b);
    }
    lca.gen();
    int q;
    while(cin >> q) {
        int max_depth = 0, leaf;
        vi v(q);
        rep(i,0,q) {
            cin >> v[i]; v[i]--;
            if(lca.depth[v[i]] > max_depth) {
                leaf = v[i];
                max_depth = lca.depth[v[i]];
            }
        }
        if(q == 1) {
            cout << "YES\n";
            continue;
        }
        bool ok = true;
        for (int x : v) {
            if (x == leaf) continue;
            int r = lca.lca(x, leaf);
            if(lca.depth[x] - lca.depth[r] > 1) {
                ok = false;
                break;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}