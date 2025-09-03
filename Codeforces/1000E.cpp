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

vi num, low;
int cnt, root;
set<ii> puentes;

void dfs(int u, vvi const &g, int parent = -1) {
    num[u] = low[u] = cnt++;
    for (int v : g[u]) {
        if (v != parent) {
            if (num[v] == 0) {
                if (parent == -1)
                    ++root;
                dfs(v, g, u);
                if (low[v] >= num[u] && parent != -1) {
                    // u es punto de articulacion
                }
                if (low[v] > num[u]) {
                    puentes.insert({min(u, v), max(u, v)});
                }
                low[u] = min(low[u], low[v]);
            } else
                low[u] = min(low[u], num[v]);
        }
    }
}

int cur_comp;
vi componentes;

void dfs1(int a, vvi const& g) {
    componentes[a] = cur_comp;
    for(int b : g[a]) {
        if(puentes.count({min(a, b), max(a, b)})) continue;
        if(componentes[b] == -1)
            dfs1(b, g);
    }
}

vi dist;
int max_dist, lejano;

void bfs(int src, vvi const& g) {
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : g[u]) {
            if(dist[v] < INT_MAX) continue;
            dist[v] = dist[u] + 1;
            if(max_dist < dist[v]) {
                max_dist = dist[v];
                lejano = v;
            }
            q.push(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vvi g(n);  // crear grafo //
    rep(i,0,m) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    low.assign(n, -1);
    num.assign(n, 0);
    cnt = 1;
    for (int i = 0; i < n; ++i) {
        if (num[i] == 0)
            dfs(i, g);
    }
    componentes.assign(n, -1);
    cur_comp = 0;
    for(int i = 0; i < n; i++) {
        if(componentes[i] == -1) {
            dfs1(i, g);
            cur_comp++;
        }
    }
    vvi g_componentes(cur_comp);
    for(ii e : puentes) {
        g_componentes[componentes[e.first]].push_back(componentes[e.second]);
        g_componentes[componentes[e.second]].push_back(componentes[e.first]);
    }
    dist.assign(sz(g_componentes), INT_MAX);
    max_dist = 0;
    bfs(0, g_componentes);
    dist.assign(sz(g_componentes), INT_MAX);
    max_dist = 0;
    bfs(lejano, g_componentes);
    cout << max_dist << '\n';
    return 0;
}