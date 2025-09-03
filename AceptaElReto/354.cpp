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

bool resuelveCaso() {
    int n; cin >> n;
    if(!n) return false;
    vi v(n);
    for(int & x : v) cin >> x;
    vi maximos(n), minimos(n);
    maximos[0] = v[0];
    minimos[n - 1] = v[n - 1];
    rep(i,1,n) maximos[i] = max(maximos[i - 1], v[i]);
    for(int i = n - 2; i >= 0; i--) {
        minimos[i] = min(minimos[i + 1], v[i]);
    }
    int sol = n;
    rep(i,0,n - 1){
        if(maximos[i] < minimos[i + 1]) {
            sol = i + 1;
            break;
        }
    }
    cout << sol << endl;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso());
    return 0;
}