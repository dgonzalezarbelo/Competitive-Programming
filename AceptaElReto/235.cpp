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
    unordered_map<char, ll> orden;
    orden['B'] = 0;
    orden['R'] = 1;
    orden['A'] = 2;
    orden['N'] = 3;
    orden['V'] = 4;
    orden['M'] = 5;
    int f, c;
    while(cin >> f >> c && f && c) {
        vector<vector<char>> mat(3 * f, vector<char>(3 * c));
        unordered_map<int, ii> posiciones;
        rep(i,0,3*f) rep(j,0,3*c) cin >> mat[i][j];
        rep(i,0,f) rep(j,0,c) {
            ll hash = 0;
            rep(k,0,9) {
                hash *= 10;
                hash += orden[mat[3 * i + (k / 3)][3 * j + (k % 3)]];
            }
            if(!posiciones.count(hash))
                posiciones[hash] = {i, j};
        }
        int q; cin >> q;
        while(q--) {
            ll hash = 0;
            rep(i,0,3) rep(j,0,3) {
                char c; cin >> c;
                hash *= 10;
                hash += orden[c];
            }
            if(posiciones.count(hash))
                cout << posiciones[hash].first + 1 << ' ' << posiciones[hash].second + 1 << '\n';
            else
                cout << "NO SE USA\n";
        }
    }
    return 0;
}