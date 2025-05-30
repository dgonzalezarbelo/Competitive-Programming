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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vi portales(k);
    for(int i = 0; i < k; i++) {
        int a; cin >> a;
        a--;
        portales[i] = a;
    }
    vvi al(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    int INF = n + 1;
    vi dist_fin(n, INF);
    dist_fin[n - 1] = 0;
    queue<int> q;
    q.push(n - 1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int b : al[u]) {
            if(dist_fin[u] + 1 < dist_fin[b]) {
                dist_fin[b] = dist_fin[u] + 1;
                q.push(b);
            }
        }
    }
    vi dist_ini(n, INF);
    dist_ini[0] = 0;
    q.push(0);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int b : al[u]) {
            if(dist_ini[u] + 1 < dist_ini[b]) {
                dist_ini[b] = dist_ini[u] + 1;
                q.push(b);
            }
        }
    }
    int suma = 0;
    int min_ini = INF, a_fin = INF, min_fin = INF;
    for(int x : portales) {
        suma += dist_fin[x];
        if(dist_ini[x] < min_ini){
            min_ini = dist_ini[x];
            a_fin = dist_fin[x];
        }
        else if(dist_ini[x] == min_ini) a_fin = min(a_fin, dist_fin[x]);
        min_fin = min(min_fin, dist_fin[x]);
    }
    ii directo = {dist_fin[0], 1};
    int num = (k - 1) * min_ini + suma - a_fin;
    int den = k - 1;
    int d = __gcd(num, den);
    num /= d; den /= d;
    ii esperanza = {num, den};
    if(directo.first * esperanza.second <= directo.second * esperanza.first)
        cout << directo.first << '/' << directo.second << '\n';
    else
        cout << esperanza.first << '/' << esperanza.second << '\n';
    return 0;
}