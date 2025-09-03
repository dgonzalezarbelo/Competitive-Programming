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

ull pow(ull a, ull exp) {
    if(exp == 0) return 1;
    if(exp == 1) return a;
    ull m = pow(a, exp / 2);
    if(exp % 2 == 0) return m * m;
    return m * m * a;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    ull a, b, c;
    while(cin >> a >> b >> c && (a || b || c)) {
        // a + a * b + a * b^2 + ... + a * b^(c - 1) = a * (b^c - 1) / b - 1
        ull res = 1, cur = b;
        if(b != 1) {
            for(ull e = 1; e < c; e++) {
                res += cur;
                cur *= b;
            }
            res *= a;
        }
        else
            res = a * c;
        cout << res << '\n';
        assert(res >= 0);
    }
    return 0;
}