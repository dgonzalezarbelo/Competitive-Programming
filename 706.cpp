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
#define int ll
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

vector<vii> al;
vi dist;
vector<set<ii>> parents;

const int D_MAX = LLONG_MAX;

void dijkstra(int source, bool solo_usables, vector<set<ii>> & no_usables) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[source] = 0;
    pq.push({0, source});
    while(!pq.empty()) {
        ii p = pq.top(); pq.pop();
        int d = p.first, u = p.second;
        if(d > dist[u]) continue;
        for(ii a : al[u]) {
            int c = a.first, v = a.second;
            if(solo_usables && no_usables[u].count({c, v})) continue;
            if(d + c < dist[v]) {
                dist[v] = d + c;
                while(!parents[v].empty()) {
                    parents[v].erase(*(parents[v].begin()));
                }
                parents[v].insert({c, u});
                pq.push({d + c, v});
            }
            else if(d + c == dist[v]) {
                parents[v].insert({c, u});
            }
        }
    }
}

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int v, e;
    while(cin >> v >> e) {
        al.assign(v, vii());
        dist.assign(v, D_MAX);
        parents.assign(v, set<ii>());
        vector<set<ii>> no_usables(v);
        rep(i,0,e) {
            int a, b, c; cin >> a >> b >> c;
            a--; b--;
            al[a].push_back({c, b});
            al[b].push_back({c, a});
            //assert(c > 0);
        }
        dijkstra(0, false, no_usables);
        set<int> padres_quitar, padres_quitados;
        padres_quitar.insert(v - 1);
        while(!padres_quitar.empty()) {
            int i = *(padres_quitar.begin());
            padres_quitar.erase(i);
            padres_quitados.insert(i);
            //printf("dist[%d] = %d\n", i, dist[i]);
            for(ii padre : parents[i]) {
                //cout << i << " -> " << a.second << " no usable\n";
                no_usables[i].insert(padre);
                no_usables[padre.second].insert({padre.first, i});
                if(!padres_quitados.count(padre.second))
                    padres_quitar.insert(padre.second);
            }
        }
        dist.assign(v, D_MAX);
        dijkstra(0, true, no_usables);
        if(dist[v - 1] < D_MAX) cout << dist[v - 1] << '\n';
        else cout << "IMPOSIBLE\n";
    }
    return 0;
}