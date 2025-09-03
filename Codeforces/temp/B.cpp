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
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vi v(n);
        rep(i,0,n) cin >> v[i];
        if(n == k) {
            int sol = -1;
            for(int i = 0; 2 * i + 1 < n; i++) {
                if(v[2 * i + 1] != i + 1) {
                    sol = i + 1;
                    break;
                }
            }
            if(sol != -1) cout << sol << '\n';
            else cout << k / 2 + 1 << '\n';
        }
        else {
            bool sol = false;
            rep(i,0,n - k + 1) {
                if(i >= n) break;
                if(v[i + 1] != 1) {
                    sol = true;
                    cout << 1 << '\n';
                    break;
                }
            }
            if(!sol) cout << 2 << '\n';
        }
    }
    return 0;
}