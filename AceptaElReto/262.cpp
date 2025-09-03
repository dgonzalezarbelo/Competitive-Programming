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

const int mod = 46337;

int pow(int n, int p) {
    if(p == 0) return 1;
    if(p == 1) return n;
    int m = pow(n, p / 2);
    m = (m * m) % mod;
    if(p % 2 == 0) return m;
    else return (m * n) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p;
    while(cin >> n >> p && n && p) {
        int sol = 0;
        rep(i,1,n+1) {
            sol += pow(i, p);
            sol %= mod;
        }
        cout << sol << '\n';
    }
    return 0;
}