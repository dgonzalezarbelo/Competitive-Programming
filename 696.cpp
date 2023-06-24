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

bool solve() {
    ll n; cin >> n;
    if(!cin) return false;
    vi v;
    ll maximo = LLONG_MIN, minimo = LLONG_MAX;
    ll suma = 0;
    while(n) {
        v.push_back(n);
        maximo = max(maximo, n);
        minimo = min(minimo, n);
        suma += n;
        cin >> n;
    }
    cout << (maximo * (maximo + 1)) / 2 - (minimo * (minimo - 1)) / 2 - suma << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(solve());
    return 0;
}