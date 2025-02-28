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

vii v;
vector<vvi> dp;
int n;
vvi dist;
int max_recorrido;

const int cota = 1e7;

int man(ii p1, ii p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int solve(int a, int b, int prev) {
    if(a == n + 1 && b == n + 1) return 0;
    if(dp[a][b][prev] != cota) return dp[a][b][prev];
    int ultimo;
    if(a > b) ultimo = a;
    else ultimo = b;
    int sig = min(n + 1, max(a, b) + 1);
    int sol = cota;
    if(a < n + 1) { // Al siguiente botón va "a"
        int coste;
        if(ultimo == a) { // Al último botón fue "a"
            coste = man(v[a], v[sig]);
            sol = min(sol, coste + solve(sig, b, prev));
        }
        else { // Al último botón fue "b"
            coste = max(0, man(v[a], v[sig]) - dist[prev][b]);
            sol = min(sol, coste + solve(sig, b, a));
        }
    }
    if(b < n + 1) { // Al siguiente botón va "b"
        int coste;
        if(ultimo == b) { // Al último botón fue "b"
            coste = man(v[b], v[sig]);
            sol = min(sol, coste + solve(a, sig, recorrido + coste));
        }
        else { // Al último botón fue "a"
            coste = max(0, man(v[b], v[sig]) - recorrido);
            sol = min(sol, coste + solve(a, sig, coste));
        }
    }
    return dp[a][b][recorrido] = sol;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int f, c;
    while(cin >> f >> c) {
        max_recorrido = f * c + 1;
        cin >> n;
        dp.assign(n + 2, vvi(n + 2, vi(max_recorrido + 1, cota)));
        v.assign(n + 2, {});
        v[0] = {1, 1};
        rep(i,1,n+1) {
            int a, b; cin >> a >> b;
            v[i] = {a, b};
        }
        v[n + 1] = {f + 1, c};
        dist.assign(n + 2, vi(n + 2));
        rep(i,0,n+2) dist[i][i] = 0;
        for(int i = n; i >= 0; i--) {
            for(int j = i + 1; j <= n + 1; j++) {
                dist[i][j] = dist[i + 1][j] + man(v[i], v[i + 1]);
            }
        }
        cout << solve(0, 0, 0) << '\n';
    }    
    return 0;
}