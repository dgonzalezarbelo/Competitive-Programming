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

struct comp {
    bool operator() (pair<ii, int> const& p1, pair<ii, int> const& p2) {
        return p1.second < p2.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi v(n);
        rep(i,0,n) v[i] = i;
        vector<pair<ii, int>> cambios;
        rep(i,0,n-1) {
            int m; cin >> m;
            while(m--) {
                int a; cin >> a;
                cambios.push_back({{i, i + 1}, a});
            }
        }
        sort(all(cambios), comp());
        for(pair<ii, int> p : cambios) {
            swap(v[p.first.first], v[p.first.second]);
        }
        int peor = 0, igual = 0, mejor = 0;
        rep(i,0,n) {
            if(v[i] < i) mejor++;
            else if(v[i] == i) igual++;
            else peor++;
        }
        cout << peor << ' ' << igual << ' ' << mejor << endl;
    }
    return 0;
}