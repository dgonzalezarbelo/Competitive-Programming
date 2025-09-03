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

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow()  { return max(oc - c, 0LL); }
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int & i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if( ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        rep(L, 0, 31) do {
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while(qi < qe && !lvl[t]) {
                int v = q[qi++];
                for(Edge e : adj[v])
                    if(!lvl[e.to] && e.c >> (30 - L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while(ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while(lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

void resuelveCaso() {
    int n, m; cin >> n >> m; cin.get();
    vector<vector<char>> mat(n, vector<char>(m));
    ll s, t;
    rep(i,0,n) {
        string str;
        getline(cin, str);
        rep(j,0,m) {
            mat[i][j] = str[j];
            if(mat[i][j] == 'C') s = i * m + j;
            if(mat[i][j] == 'L') t = i * m + j;
        }
    }
    int os, ot;
    Dinic din(2*(n * m) + 2);
    rep(i,0,n) {
        rep(j,0,m) {
            if(mat[i][j] == '#') continue;
            if(abs(s - i*m-j) <= 1 || abs(s - i*m-j) == m) din.addEdge(2*(i*m+j), 2*(i*m+j) + 1, INF);
            else din.addEdge(2*(i*m+j), 2*(i*m+j) + 1, 1);
            if(mat[i][j] == 'C') os = 2*(i * m + j);
            if(mat[i][j] == 'L') ot = 2*(i * m + j);
            if(i > 0 && mat[i - 1][j] != '#') din.addEdge(2*(i * m + j) + 1, 2*((i-1)*m + j), INF);
            if(i < n - 1 && mat[i + 1][j] != '#') din.addEdge(2*(i * m + j) + 1, 2*((i+1)*m + j), INF);
            if(j > 0 && mat[i][j - 1] != '#') din.addEdge(2*(i * m + j)+1, 2*(i*m + j - 1), INF);
            if(j < m - 1 && mat[i][j + 1] != '#') din.addEdge(2*(i * m + j)+1, 2*(i*m + j + 1), INF);
        }
    }
    int il = t / m, jl = t % m;
    if(abs(s - t) == 1 || abs(s - t) == m) cout << "IMPOSIBLE\n";
    else if(il < n - 2 && mat[il + 1][jl] == '.' && mat[il + 2][jl] == 'C') cout << "IMPOSIBLE\n";
    else if(il >= 2 && mat[il - 1][jl] == '.' && mat[il - 2][jl] == 'C') cout << "IMPOSIBLE\n";
    else if(jl < m - 2 && mat[il][jl + 1] == '.' && mat[il][jl + 2] == 'C') cout << "IMPOSIBLE\n";
    else if(jl >= 2 && mat[il][jl - 1] == '.' && mat[il][jl - 2] == 'C') cout << "IMPOSIBLE\n";
    else if(il < n - 1 && jl < m - 1 && (mat[il + 1][jl] == '.' || mat[il][jl + 1] == '.') && mat[il + 1][jl + 1] == 'C') cout << "IMPOSIBLE\n";
    else if(il > 0 && jl < m - 1 && (mat[il - 1][jl] == '.' || mat[il][jl + 1] == '.') && mat[il - 1][jl + 1] == 'C') cout << "IMPOSIBLE\n";
    else if(il > 0 && jl > 0 && (mat[il - 1][jl] == '.' || mat[il][jl - 1] == '.') && mat[il - 1][jl - 1] == 'C') cout << "IMPOSIBLE\n";
    else if(il < n - 1 && jl > 0 && (mat[il + 1][jl] == '.' || mat[il][jl - 1] == '.') && mat[il + 1][jl - 1] == 'C') cout << "IMPOSIBLE\n";
    else {
        ll flow = din.calc(os,ot);
        if(abs(flow) > 4) cout << "IMPOSIBLE\n";
        else cout << flow << endl;
        //cout << flow << endl;
        //assert(flow <= 4); //Ha dado RTE
    }
}

int main() {
    int t; cin >> t;
    while(t--) resuelveCaso();
    return 0;
}