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

const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        ll n, a, b; cin >> n >> a >> b;
        ll cur = 1;
        ll sq = n * n;
        ll sol = 0;
        for(ll c = 0; c < b; c++) {
            cur *= (sq - c);
            cur %= mod;
            if(c + 1 >= a && c + 1 <= b) {
                sol += cur;
                sol %= mod;
            }
        }
        cout << sol << '\n';
    }
    return 0;
}