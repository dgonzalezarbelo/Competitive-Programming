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

bool resuelveCaso() {
    int n; cin >> n;
    if(!n) return false;
    vii v;
    rep(i,0,n) {
        int x, y; cin >> x >> y;
        v.push_back({x - y, 1}); //1->Entra
        v.push_back({x + y, 2}); //2->Sale
    }
    sort(all(v));
    int sol = 0;
    int cur = 0;
    for(int i = 0; i < sz(v); i++) {
        if(v[i].second == 1) cur++;
        else cur--;
        sol = max(sol, cur);
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