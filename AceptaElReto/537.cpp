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

vvi al;
vb visited;

int dfs(int a) {
    if(visited[a]) return 0;
    visited[a] = true;
    int sol = 1;
    for(int b : al[a]) {
        sol += dfs(b);
    }
    return sol;
}

bool solve() {
    int p, c; cin >> p >> c;
    if(!cin) return false;
    al.assign(p, vi());
    visited.assign(p, false);
    for(int i = 0; i < c; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    if(dfs(0) == p) cout << "BICI\n";
    else cout << "A PIE\n";
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(solve());
    return 0;
}