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
    int n, m, r, c; cin >> n >> m >> r >> c; cin.get();
    if(!n && !m && !r && !c) return 0;
    vvi mat(n, vi(m));
    rep(i,0,n) rep(j,0,m) {
        char c; cin >> c;
        if(c == '1') mat[i][j] = 1;
    }
    bool ok = true;
    bool cambiado = false;
    int esquina_i, esquina_j;
    rep(i,0,n) rep(j,0,m) {
        if(!ok) break;
        if(j == normal) cambiado = false;
        if((mat[i][j] == 0 && cambiado) || (mat[i][j] == 1 && !cambiado)) {
            if()
        }
    }
    return 0;
}