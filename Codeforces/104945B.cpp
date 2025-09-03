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

vi vis, match;
vvi g;
int n, m;
int aug(int l) {
    if (vis[l])
        return 0;
    vis[l] = 1;
    for (int r : g[l])
        if (match[r] == -1 || aug(match[r])) {
            match[r] = l;
            return 1;
        }
    return 0;
}

int berge_mcbm() {
    unordered_set<int> libres;
    for (int l = 0; l < n; ++l)
        libres.insert(l);
    int mcbm = 0;
    match.assign(n + m, -1);
    for (int l = 0; l < n; ++l) {
        vector<int> candidatos;
        for (int r : g[l])
            if (match[r] == -1)
                candidatos.push_back(r);
        if (!candidatos.empty()) {
            ++mcbm;
            libres.erase(l);
            int r = rand() % int(candidatos.size());
            match[candidatos[r]] = l;
        }
    }
    for (int l : libres) {
        vis.assign(n, 0);
        mcbm += aug(l);
    }
    return mcbm;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    g.assign(n + m, {});
    rep(i,0,n) {
        int k; cin >> k;
        rep(j,0,k) {
            int a; cin >> a; a--;
            g[i].push_back(n + a);
            g[n + a].push_back(i);
        }
    }
    cout << berge_mcbm() << '\n';
    return 0;
}