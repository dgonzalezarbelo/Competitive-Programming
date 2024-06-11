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
    vi v;
    v.push_back(n);
    cin >> n;
    while(n) {
        v.push_back(n);
        cin >> n;
    }
    vii intervalos;
    intervalos.push_back(mp(v[0], v[0]));
    rep(i,1,sz(v)) {
        if(intervalos.back().second == v[i] - 1) intervalos.back().second = v[i];
        else intervalos.push_back(mp(v[i], v[i]));
    }
    rep(i,0,sz(intervalos)) {
        if(i) cout << ',';
        if(intervalos[i].first != intervalos[i].second) cout << intervalos[i].first << '-' << intervalos[i].second;
        else cout << intervalos[i].first;
    }
    cout << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso());
    return 0;
}