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
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using db = double;
using vdb = vector<db>;
using ldb = long double; //100 ceros pero poca precision decimal

vector<unordered_set<int>> enemigos;
void dfs(int nodo, int & rojo, int & negro, vector<bool> & marcas, bool es_rojo) {
    marcas[nodo] = true;
    if(es_rojo) rojo++;
    else negro++;
    for(int x : enemigos[nodo]) {
        if(!marcas[x]) dfs(x, rojo, negro, marcas, !es_rojo);
    }
}

bool solve() {
    int n, p, a; cin >> n >> p >> a;
    if(!cin) return false;
    enemigos.assign(n + 1, {});
    for(int i = 0; i < p; i++) {
        int b, c; cin >> b >> c;
        enemigos[b].insert(c);
        enemigos[c].insert(b);
    }
    vector<bool> marcas(n + 1, false);
    vector<ii> grupos;
    for(int i = 1; i <= n; i++) {
        if(!marcas[i]) {
            ii grupo;
            dfs(i, grupo.first, grupo.second, marcas, true);
            grupos.push_back(grupo);
        }
    }
    vector<int> dp(a + 1, 0);
    for(int i = 0; i <= a; i++) {
        if(i >= grupos[grupos.size() - 1].first && i >= grupos[grupos.size() - 1].second)
            dp[i] = max(grupos[grupos.size() - 1].first, grupos[grupos.size() - 1].second);
        else if(i >= grupos[grupos.size() - 1].first) dp[i] = grupos[grupos.size() - 1].first;
        else if(i >= grupos[grupos.size() - 1].second) dp[i] = grupos[grupos.size() - 1].second;
    }
    for(int i = grupos.size() - 2; i >= 0; i--) {
        for(int j = a; j >= 0; j--) {
            if(j >= grupos[i].first && j >= grupos[i].second)
                dp[j] = max({grupos[i].first + dp[j - grupos[i].first], grupos[i].second + dp[j - grupos[i].second], dp[j]});
            else if(j >= grupos[i].first) dp[j] = max(dp[j], grupos[i].first +  dp[j - grupos[i].first]);
            else if(j >= grupos[i].second) dp[j] = max(dp[j], grupos[i].second +  dp[j - grupos[i].second]);
        }
    }
    cout << dp[a] << '\n';
    return true;
}

int main() {
    while(solve());
    return 0;
}