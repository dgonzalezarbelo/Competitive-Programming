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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll c, f, h;
    while(cin >> c >> f >> h && c && f) {
        vii v(h);
        rep(i,0,h) {
            cin >> v[i].first >> v[i].second;
        }
        sort(all(v));
        unordered_set<int> old_filas, filas;
        int old_col = -1, cur_col = -1;
        ll faltan = 0;
        rep(i,0,h) {
            int col = v[i].first, row = v[i].second;
            if(col > cur_col) {
                old_filas = filas;
                filas.clear();
                old_col = cur_col;
                cur_col = col;
            }
            if(col < c) faltan++;
            if(row < f) faltan++;
            filas.insert(row);
            if(old_col == cur_col - 1) {
                if(!old_filas.count(row)) faltan++;
            }
            else if(cur_col > 1) faltan++;
            if(row > 1 && !filas.count(row - 1)) faltan++;
        }
        cout << (c - 1) * f + (f - 1) * c - faltan << '\n';
    }
    return 0;
}