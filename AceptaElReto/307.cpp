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

bool aciclico(int a, int prev, int & sum) {
    if(visited[a]) return false;
    visited[a] = true;
    sum++;
    bool sol = true;
    for(int b : al[a]) {
        if(b != prev) sol = sol && aciclico(b, a, sum);
    }
    return sol;
}

bool solve() {
    int v, a; cin >> v >> a;
    if(!cin) return false;
    al.assign(v, vi());
    visited.assign(v, false);
    for(int i = 0; i < a; i++) {
        int a, b; cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    int sum = 0;
    bool sin_ciclo = aciclico(0, -1, sum);
    if(sin_ciclo && sum == v) cout << "SI\n";
    else cout << "NO\n";
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(solve());
    return 0;
}