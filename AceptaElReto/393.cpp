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

vi ans;

template<char A, size_t ASZ> struct ACfixed {
	struct Node { array<int, ASZ> to; int link; vii endsHere; bool end; int terminal; };
	vector<Node> d{{}};
	vi bfs;
	ACfixed(vector<string>& v) { // Initialize with patterns
		rep(i,0,sz(v)) ins(v[i], i);
		pushLinks();
	}
	void ins(string& s, int i) {
		int v = 0;
		for(char& C : s) {
			int c = C-A;
			if (!d[v].to[c]) d[v].to[c] = sz(d), d.emplace_back();
			v = d[v].to[c];
		}
		d[v].end = true;
		d[v].endsHere.emplace_back(i, sz(s));
	}
	void pushLinks() {
		d[0].link = -1;
		queue<int> q; q.push(0);
		while (sz(q)) {
			int v = q.front(); q.pop(); bfs.push_back(v);
			d[v].terminal = d[v].link == -1 ? 0 : d[d[v].link].end ? d[v].link : d[d[v].link].terminal;
			for(auto& x : d[d[v].terminal].endsHere) d[v].endsHere.push_back(x); 
		    rep(c,0,ASZ) {
				int u = d[v].to[c]; if (!u) continue;
				d[u].link = d[v].link == -1 ? 0 : d[d[v].link].to[c];
				q.push(u);
			}
			if (v) rep(c,0,ASZ) if (!d[v].to[c])
				d[v].to[c] = d[d[v].link].to[c];
		}
	}
	void solve(string& s) {
		// vector<int> ans(n);
		int cur = 0;
		rep(i,0, sz(s)) {
			cur = d[cur].to[s[i] - A];
			for(auto& p : d[cur].endsHere) ans[p.fi]++;
		}
	}
};

bool resuelveCaso() {
    int n, m; cin >> m >> n; cin.get();
    if(!cin) return false;
    vector<string> lineas(n);
    rep(i,0,n) {
        getline(cin, lineas[i]);
    }
    vector<string> verticales(m);
    rep(i,0,m) {
        rep(j,0,n) {
            verticales[i] += lineas[j][i];
        }
    }
    vector<string> diagonales(n + m - 1);
    rep(d,0,n) {
        int j = 0;
        while(d + j < n && j < m) {
            diagonales[d] += lineas[d + j][j];
            j++;
        }
    }
    rep(d,1,m) {
        int j = 0;
        while(j < n && d + j < m) {
            diagonales[n + d - 1] += lineas[j][d + j];
            j++;
        }
    }
    vector<string> inv_diagonales(n + m - 1);
    rep(d,0,n) {
        int j = 0;
        while(n - 1 - d - j >= 0 && j < m) {
            inv_diagonales[d] += lineas[n - 1 - d - j][j];
            j++;
        }
    }
    rep(d,1,m) {
        int j = 0;
        while(n - 1 - j >= 0 && d + j < m) {
            inv_diagonales[n + d - 1] += lineas[n - 1 - j][d + j];
            j++;
        }
    }
    int ceros = 0, unos = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(lineas[i][j] == '0') ceros++;
            else unos++;
        }
    }
    int q; cin >> q; cin.get();
    vector<string> queries(q);
    for(string& s : queries) cin >> s;
    sort(all(queries));
    ACfixed<'0',2> ac(queries);
    ans.assign(q, 0);
    for(string& s : lineas) {
        ac.solve(s);
        reverse(all(s));
        ac.solve(s);
    }
    for(string& s : verticales) {
        ac.solve(s);
        reverse(all(s));
        ac.solve(s);
    }
    for(string& s : diagonales) {
        ac.solve(s);
        reverse(all(s));
        ac.solve(s);
    }
    for(string& s : inv_diagonales) {
        ac.solve(s);
        reverse(all(s));
        ac.solve(s);
    }
    rep(i,0,sz(queries)) {
        string s = queries[i];
        if(s == "0") {
            if(ceros) cout << s << ' ' << ceros << endl;  
        }
        else if(s == "1") {
            if(unos) cout << s << ' ' << unos << endl;
        }
        else if(ans[i] > 0) {
            cout << s << ' ' << ans[i] << endl;
        }
    }
    cout << "---\n";
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso());
    return 0;
}