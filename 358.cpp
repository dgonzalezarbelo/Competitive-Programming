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

int n;
vvii al;

vi dijkstra(int start) {
    vi dist(n, 1e9);
    dist[start] = 0;
    vi opciones(n, 0);
    opciones[start] = 1;
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push({0, start});
    while(!pq.empty()) {
        ii top = pq.top(); pq.pop();
        int d = top.first, u = top.second;
        if(d > dist[u]) continue;
        for(ii& p : al[u]) {
            int coste = p.first, v = p.second;
            if(d + coste < dist[v]) {
                dist[v] = d + coste;
                opciones[v] = opciones[u];
                pq.push({d + coste, v});
            }
            else if(d + coste == dist[v]) {
                opciones[v] += opciones[u];
            }
        }
    }
    return opciones;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> n) {
        int e; cin >> e;
        al.assign(n, vii());
        rep(i,0,e) {
            int a, b, c; cin >> a >> b >> c;
            a--; b--;
            al[a].push_back({c, b});
            al[b].push_back({c, a});
        }
        vi opciones = dijkstra(0);
        cout << opciones[n - 1] << '\n';
    }   
    return 0;
}